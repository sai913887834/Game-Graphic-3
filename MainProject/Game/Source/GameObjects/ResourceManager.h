#pragma once

class Mesh;
class Material;

class ResourceManager {

public:
    ResourceManager();
    ~ResourceManager();


    fw::Texture* GetTexture(std::string name);
    void SetTexture(std::string name, fw::Texture* texture);


    fw::ShaderProgram* GetShader(std::string name);
    void SetShaderProgram(std::string name, fw::ShaderProgram* shader);

    Mesh* GetMesh(std::string name);
    void SetMesh(std::string name, Mesh* mesh);

    Material* GetMaterial(std::string name);
    void SetMaterial(std::string name, Material* material);


private:


    std::map<std::string, fw::Texture*> m_Textures;
    std::map<std::string, Mesh*>m_Mesh;
    std::map<std::string, fw::ShaderProgram*>m_Shader;
    std::map<std::string, Material*>m_Material;












};