#include "GamePCH.h"

#include "Base/Mesh.h"
#include "Base/VertexFormat.h"
#include "GameObjects/Camera.h"
#include "GameObjects/GameObject.h"

using namespace fw;

Mesh::Mesh()
{
    m_VBO = 0;

    m_PrimitiveType = -1;
    m_NumVerts = 0;
	//rotationX = 0;
	//rotationY = 0;
}
    
Mesh::~Mesh()
{
    glDeleteBuffers( 1, &m_VBO );
}

void Mesh::Init(VertexFormat* pVerts, int numVerts, unsigned int* pIndices, int numIndices, GLenum primitiveType, GLenum usage)
{
    m_NumVerts = numVerts;
    m_NumIndices = numIndices;
    m_PrimitiveType = primitiveType;

    // Generate and fill buffer with our vertex attributes.
    glGenBuffers( 1, &m_VBO );
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof(VertexFormat)*numVerts, pVerts, usage );

    // Generate and fill buffer with our indices.
    if( pIndices )
    {
        glGenBuffers( 1, &m_IBO );
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IBO );
        glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*numIndices, pIndices, usage );
    }
}

void Mesh::Init(VertexFormat* pVerts, unsigned int numVerts, GLenum primitiveType)
{
    Init( pVerts, numVerts, nullptr, 0, primitiveType, GL_STATIC_DRAW );
}

void Mesh::Draw(Camera* pCamera, ShaderProgram* pShader, vec3 pos, fw::Texture* pTexture)
{
    assert( m_PrimitiveType != -1 );
    assert( m_NumVerts != 0 );


	//glRotatef(rotationX, 1, 0, 0);
	//glRotatef(rotationY, 0, 1, 0);
    // Setup attributes.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_IBO );

    GLint locPosition = glGetAttribLocation( pShader->GetProgram(), "a_Position" );
    if( locPosition != -1 )
    {
        glVertexAttribPointer( locPosition, 3, GL_FLOAT, GL_FALSE, 24, (void*)0 );
        glEnableVertexAttribArray( locPosition );
    }

    GLint locColor = glGetAttribLocation( pShader->GetProgram(), "a_Color" );
    if( locColor != -1 )
    {
        glVertexAttribPointer( locColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, 24, (void*)12 );
        glEnableVertexAttribArray( locColor );
    }

    GLint locUV = glGetAttribLocation( pShader->GetProgram(), "a_UV" );
    if( locUV != -1 )
    {
        glVertexAttribPointer( locUV, 2, GL_FLOAT, GL_FALSE, 24, (void*)16 );
        glEnableVertexAttribArray( locUV );
    }

    // Enable shader and setup uniforms.
    glUseProgram( pShader->GetProgram() );

    GLint uWorldMat = glGetUniformLocation( pShader->GetProgram(), "u_WorldMat" );
    if(uWorldMat != -1 )
    {
        mat4 mat;
        mat.SetIdentity();
        mat.CreateSRT(1, vec3(pos.x,pos.y,pos.z), 0);

        glUniformMatrix4fv(uWorldMat, 1, false,&mat.m11 );
      
        
        //mat.SetTranslation(pos.x, pos.y, 0);
            //pos.x, pos.y );
    }

    GLint uCameraTranslation = glGetUniformLocation( pShader->GetProgram(), "u_CameraTranslation" );
    if( uCameraTranslation != -1 )
    {
        glUniform2f( uCameraTranslation, -pCamera->GetPosition().x, -pCamera->GetPosition().y );
    }

    GLint uProjectionScale = glGetUniformLocation( pShader->GetProgram(), "u_ProjectionScale" );
    if( uProjectionScale != -1 )
    {
        glUniform2f( uProjectionScale, pCamera->GetProjectionScale().x, pCamera->GetProjectionScale().y );
    }

    // Setup the texture.
    int textureUnit = 0;
    glActiveTexture( GL_TEXTURE0 + textureUnit );
    glBindTexture( GL_TEXTURE_2D, pTexture->GetTextureID() );
    GLint uTexture = glGetUniformLocation( pShader->GetProgram(), "u_Texture" );
    if( uTexture != -1 )
    {
        glUniform1i( uTexture, textureUnit );
    }

    // Draw.
    if( m_NumIndices == 0 )
    {
        glDrawArrays( m_PrimitiveType, 0, m_NumVerts );   
    }
    else
    {
        glDrawElements( m_PrimitiveType, m_NumIndices, GL_UNSIGNED_INT, nullptr );
    }
}

void Mesh::CreateBox(vec3 size, vec3 offset)
{
    // ATM this can only be called once, so we assert if it's called again with a VBO already allocated.
    assert( m_VBO == 0 );

    VertexFormat vertexAttributes[] =
    {

		// front 
        VertexFormat( vec3( -size.x, -size.y ,-size.z) + offset, ColorByte( 255, 255, 255, 255 ), vec2( 0.0f, 0.5f ) ),
        VertexFormat( vec3( -size.x,  size.y ,-size.z) + offset, ColorByte( 255, 255, 255, 255 ), vec2( 0.0f, 1.0f ) ),
        VertexFormat( vec3(  size.x,  size.y ,-size.z) + offset, ColorByte( 255, 255, 255, 255 ), vec2( 0.3f, 1.0f ) ),
        VertexFormat( vec3(  size.x, -size.y ,-size.z) + offset, ColorByte( 255, 255, 255, 255 ), vec2( 0.3f, 0.5f ) ),


		//Back	
		VertexFormat(vec3(-size.x, -size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.4f, 0.5f)),
		VertexFormat(vec3(-size.x,  size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.4f, 1.0f)),
		VertexFormat(vec3(size.x,  size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.7f, 1.0f)),
		VertexFormat(vec3(size.x, -size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.7f, 0.5f)),


		//Left
		VertexFormat(vec3(-size.x,-size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.8f, 0.5f)),
		VertexFormat(vec3(-size.x,  size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.8f, 1.0f)),
		VertexFormat(vec3(-size.x,  size.y ,-size.z) + offset, ColorByte(255, 255, 255, 255), vec2(1.0f, 1.0f)),
		VertexFormat(vec3(-size.x, -size.y ,-size.z) + offset, ColorByte(255, 255, 255, 255), vec2(1.0f, 0.5f)),

		//RIGHT
			
		VertexFormat(vec3(size.x, -size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.0f, 0.0f)),
		VertexFormat(vec3(size.x,  size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.0f, 0.4f)),
		VertexFormat(vec3(size.x,  size.y ,-size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.3f, 0.4f)),
		VertexFormat(vec3(size.x, -size.y ,-size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.3f, 0.0f)),

		//TOP
		VertexFormat(vec3(-size.x, size.y ,-size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.4f, 0.0f)),
		VertexFormat(vec3(-size.x,  size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.4f, 0.4f)),
		VertexFormat(vec3(size.x,  size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.7f, 0.4f)),
		VertexFormat(vec3(size.x, size.y ,-size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.7f, 0.0f)),

		//BOTTOM
			
		VertexFormat(vec3(-size.x, -size.y ,-size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.8f, 0.0f)),
		VertexFormat(vec3(-size.x,  -size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(0.8f, 0.4f)),
		VertexFormat(vec3(size.x,  -size.y ,size.z) + offset, ColorByte(255, 255, 255, 255), vec2(1.0f, 0.4f)),
		VertexFormat(vec3(size.x, -size.y ,-size.z) + offset, ColorByte(255, 255, 255, 255), vec2(1.0f, 0.0f)),

    };

    unsigned int indices[36] = { 0,2,1,0,3,2,  4,6,5,4,7,6,  8,10,9,8,11,10,  12,14,13,12,15,14,  16,18,15,16,19,18,  20,22,21,20,23,22 };

   // unsigned int indices[36] = { 0,  1,  2,  0,  2,  3,   //front
 //4,  5,  6,  4,  6,  7,   //right
// 8,  9,  10, 8,  10, 11,  //back
// 12, 13, 14, 12, 14, 15,  //left
 //16, 17, 18, 16, 18, 19,  //upper
 //20, 21, 22, 20, 22, 23 };
	//unsigned int indices[24] = { 0,2,1, 0,3,2, 4,6,5,4,7,6, 8,10,9,8,11,10,  12,14,13,12,15,14, };
    Init( vertexAttributes, 24, indices, 36, GL_TRIANGLES, GL_STATIC_DRAW );
	//Init(vertexAttributes, 16, indices, 24, GL_TRIANGLES, GL_STATIC_DRAW);
};
