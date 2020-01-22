#pragma once
//#include"GameObject.h"


class Material {

   
public:


    Material(fw::ShaderProgram shader, fw::Texture texture);
    ~Material();

    fw::ShaderProgram* GetShader();
    fw::Texture* GetTexture();
private:
    
    fw::ShaderProgram* m_Shader;
    fw::Texture* m_Texture;




};