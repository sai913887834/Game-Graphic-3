#include "GamePCH.h"

#include "Base/Mesh.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Camera.h"
#include "Game.h"

using namespace fw;

Camera::Camera(Game* pGame, vec3 position, vec2 projectionScale)
: GameObject( pGame, nullptr, nullptr, 0, position )

{
	m_ViewMatrix.CreateLookAtView(vec3(0, 0, -6), vec3(0, 1, 0), vec3(0,0,0));
	m_ProjMatrix.CreatePerspectiveHFoV(90.f, 1.f, 0.01f, 100.f);
	
}
    
Camera::~Camera()
{
}
