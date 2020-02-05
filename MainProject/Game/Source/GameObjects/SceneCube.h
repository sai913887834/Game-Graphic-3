#pragma once
#include"Scene.h"
class Player;
class Camera;
class Game;
class Mesh;
class PlayerController;

class SceneCube : public Scene {

public:
    SceneCube(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec3 position, int playerNum, PlayerController* pController, vec2 projectionScale);
    ~SceneCube();
    void Init();
    void Update(float delta);
    void Draw();
    

private:
    
   

    


   




};