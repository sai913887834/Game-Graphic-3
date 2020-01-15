#version 120

attribute vec2 a_Position;
attribute vec2 a_UV;

uniform mat4 u_WorldMat;
uniform vec2 u_ObjectTranslation;
uniform vec2 u_CameraTranslation;
uniform vec2 u_ProjectionScale;

varying vec2 v_UV;

void main()
{
    vec4 objectPos = vec4(a_Position,0,1); 

	vec4  worldPos = u_WorldMat *objectPos;
    vec4    viewPos = worldPos + vec4(u_CameraTranslation,0,0);
	vec4 clipPos = viewPos * vec4(u_ProjectionScale,1,1);


    gl_Position = clipPos;

    v_UV = a_UV;
}
