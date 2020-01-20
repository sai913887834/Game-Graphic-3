#pragma once
#include"Scene.h"
class Player;
class Camera;
class Game;
class Mesh;
class PlayerController;

class SceneCube : public Scene {

public:
    SceneCube(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec2 position, int playerNum, PlayerController* pController, vec2 projectionScale);
    ~SceneCube();
    void Init();
    void Update(float delta);
    void Draw();
    

private:
    Player* m_pPlayer;
    Camera* m_pCamera;









};