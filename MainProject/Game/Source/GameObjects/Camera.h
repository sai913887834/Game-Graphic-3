#ifndef __Camera_H__
#define __Camera_H__

#include "GameObject.h"

class Game;

class Camera : public GameObject
{
protected:
   // vec2 m_ProjectionScale;
	mat4 m_ProjMatrix;
	mat4 m_ViewMatrix;
public:
    Camera(Game* pGame, vec3 position, vec2 projectionScale);
    ~Camera();

	mat4 GetProjectionMatrix() { return m_ProjMatrix; }
	mat4 GetViewMatrix() { return m_ViewMatrix; }


};

#endif //__Camera_H__
