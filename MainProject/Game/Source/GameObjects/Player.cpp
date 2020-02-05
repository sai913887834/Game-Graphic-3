#include "GamePCH.h"

#include "Game.h"
#include "Base/Mesh.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Player.h"
#include "GameObjects/PlayerController.h"

using namespace fw;

Player::Player(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec3 position, int playerNum, PlayerController* pController)
: GameObject( pGame, pMesh, pShader, pTexture, position )
, m_PlayerNumber( playerNum )
, m_pController( pController )
{
   // pGame->GetPhysicsWorld()->CreateBody(position, 0, true, this);
	
		m_pBody = pGame->GetPhysicsWorld()->CreateBody(position, 0, true, this);
		m_pBody->AddBox(vec3(1),vec3(1));
}
    
Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    GameObject::Update( deltaTime);

    float speed = 100;
    vec2 dir( 0, 0 );

	if (m_pController->m_Up)
		   dir.y = 1;
		//m_pMesh->rotationX -= speed*deltaTime;
	
	if (m_pController->m_Down)
		 dir.y = -1;
		//m_pMesh->rotationX += speed * deltaTime;
    if( m_pController->m_Left )
       dir.x = -1;

		//m_pMesh->rotationY += speed * deltaTime;
    if( m_pController->m_Right )
        dir.x = 1;
		//m_pMesh->rotationX -= speed * deltaTime;

    m_Position += dir * speed * deltaTime;
}
