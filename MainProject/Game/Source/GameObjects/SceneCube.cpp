
#include "GamePCH.h"
#include "SceneCube.h"

#include"Player.h"
#include "Camera.h"
#include"PlayerController.h"

SceneCube::SceneCube(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec2 position, int playerNum, PlayerController* pController, vec2 projectionScale)
{
    m_pPlayer = new Player(pGame, pMesh, pShader, pTexture, position, playerNum, pController);
    m_pCamera = new Camera(pGame, position, projectionScale);
}

SceneCube::~SceneCube()
{
    delete m_pCamera;
    delete m_pPlayer;
}

void SceneCube::Init()
{
}

void SceneCube::Update(float delta)
{
    m_pCamera->Update(delta);
    m_pPlayer->Update(delta);
}

void SceneCube::Draw()
{
    //m_pCamera->Draw();
    m_pPlayer->Draw(m_pCamera);
}
