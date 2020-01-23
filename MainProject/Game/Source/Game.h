#ifndef __Game_H__
#define __Game_H__

class Ball;
//class Camera;
class GameObject;
class ImGuiManager;
class Mesh;
//class Player;
class PlayerController;
class ResourceManager;
class SceneCube;

class Game : public fw::GameCore
{
protected:
    fw::ImGuiManager* m_pImGuiManager;

    ResourceManager* m_ResourceManager;

    fw::ShaderProgram* m_pShaderTexture;
    Mesh* m_pMeshBox;
    fw::Texture* m_pTexture;

    //Player* m_pPlayer;
    //Camera* m_pCamera;
    SceneCube* m_pSceneCube;



    PlayerController* m_pController;
    fw::PhysicsWorld* m_pPhysicsWorld;

public:
    Game(fw::Framework* pFramework);
    virtual ~Game();

    virtual void Init() override;
    virtual void OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    fw::PhysicsWorld* GetPhysicsWorld();

};

#endif //__Game_H__
