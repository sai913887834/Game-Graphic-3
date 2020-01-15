#include "GamePCH.h"
#include "ResourceManager.h"
#include "Base/Mesh.h"


ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
    for (auto it : m_Mesh) {

        delete it.second;

    }
    m_Mesh.clear();

    for (auto it : m_Textures) {

        delete it.second;

    }
    m_Textures.clear();

    for (auto it : m_Shader) {

        delete it.second;

    }
    m_Shader.clear();

}

fw::Texture* ResourceManager::GetTexture(std::string name)
{
    if (m_Textures.find(name) == m_Textures.end()) {

        
        return nullptr;

    }
    

    return m_Textures.at(name);
        
}
void ResourceManager::SetTexture(std::string name, fw::Texture* texture)
{
    assert(m_Textures.find(name) == m_Textures.end());
    {

        //m_Shader.insert(std::make_pair(name, shader));
        m_Textures[name] = texture;

    }
}

fw::ShaderProgram* ResourceManager::GetShader(std::string name)
{
    if (m_Shader.find(name) == m_Shader.end()) {


        return nullptr;

    }


    return m_Shader.at(name);
}

void ResourceManager::SetShaderProgram(std::string name, fw::ShaderProgram* shader)
{

    assert(m_Shader.find(name) == m_Shader.end());
    {

        //m_Shader.insert(std::make_pair(name, shader));
        m_Shader[name] = shader;

    }
}

Mesh* ResourceManager::GetMesh(std::string name)
{
    if (m_Mesh.find(name) == m_Mesh.end()) {


        return nullptr;

    }


    return m_Mesh.at(name);
}

void ResourceManager::SetMesh(std::string name, Mesh* mesh)
{


    assert(m_Mesh.find(name) == m_Mesh.end());
    {

        //m_Shader.insert(std::make_pair(name, shader));
        m_Mesh[name] = mesh;

    }
}


