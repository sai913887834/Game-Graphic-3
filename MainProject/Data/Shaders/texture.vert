#version 120

attribute vec3 a_Position;
attribute vec2 a_UV;

uniform mat4 u_WorldMat;
//uniform vec2 u_ObjectTranslation;
//uniform vec2 u_CameraTranslation;
//uniform vec2 u_ProjectionScale;
uniform mat4 u_ViewMatrix;
uniform mat4 u_ProjMatrix;


varying vec2 v_UV;

void main()
{
    vec4 objectPos = vec4(a_Position,1); 

	vec4  worldPos = u_WorldMat *objectPos;
    vec4    viewPos = u_ViewMatrix * worldPos;
	vec4 clipPos = u_ProjMatrix * viewPos;


    gl_Position = clipPos;

    v_UV = a_UV;
}
