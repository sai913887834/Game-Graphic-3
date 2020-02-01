#include "GamePCH.h"

#include "Base/Mesh.h"
#include "GameObjects/Camera.h"
#include "GameObjects/GameObject.h"

using namespace fw;

GameObject::GameObject(Game* pGame, Mesh* pMesh, ShaderProgram* pShader, fw::Texture* pTexture, vec3 position)
: m_pGame( pGame )
, m_pMesh( pMesh )
, m_pShader( pShader )
, m_pTexture( pTexture )
, m_Position( position )
, m_Radius( 2 )
{
	m_pBody = nullptr;
}

GameObject::~GameObject()
{

}

void GameObject::Update(float deltaTime)
{
	if (m_pBody != nullptr) {
		m_Position = m_pBody->GetPosition();
		//ImGui::Text("postiion %.2f,%.2f", m_pBody->GetPosition().x, m_pBody->GetPosition().y);
	}
}

void GameObject::Draw(Camera* pCamera)
{
	if( m_pMesh != 0 )
        m_pMesh->Draw( pCamera, m_pShader, m_Position, m_pTexture );
}

bool GameObject::IsColliding(GameObject* pOtherGameObject)
{
    float radii = m_Radius + pOtherGameObject->m_Radius;
    if( (m_Position - pOtherGameObject->m_Position).Length() < radii )
        return true;

    return false;
}

void GameObject::OnCollision(GameObject* pOtherGameObject)
{
}

void GameObject::AddBox(vec3 size, vec3 offset)
{

	m_pBody->AddBox(size, offset);

}
