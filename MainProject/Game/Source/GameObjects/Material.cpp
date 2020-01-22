#include"GamePCH.h"
#include "Material.h"
#include"Base/Mesh.h"


Material::Material(fw::ShaderProgram shader, fw::Texture texture)
{
    m_Shader = &shader;
    m_Texture = &texture;

}

Material::~Material()
{
}

fw::ShaderProgram* Material::GetShader()
{
    return m_Shader;
}

fw::Texture* Material::GetTexture()
{
    return m_Texture;
}

