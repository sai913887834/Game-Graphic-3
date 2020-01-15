#pragma once

class Mesh;

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



private:


    std::map<std::string, fw::Texture*> m_Textures;
    std::map<std::string, Mesh*>m_Mesh;
    std::map<std::string, fw::ShaderProgram*>m_Shader;












};