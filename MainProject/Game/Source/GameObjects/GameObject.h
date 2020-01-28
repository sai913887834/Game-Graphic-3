#ifndef __GameObject_H__
#define __GameObject_H__

class Game;
class Mesh;

class GameObject
{
protected:
    Game* m_pGame;
    Mesh* m_pMesh;
    fw::ShaderProgram* m_pShader;
    fw::Texture* m_pTexture;
    vec3 m_Position;
    float m_Radius;

public:
    GameObject(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec3 position);
    ~GameObject();

    vec3 GetPosition() { return m_Position; }
    float GetRadius() { return m_Radius; }

    void SetPosition(vec3 pos) { m_Position = pos; }

    virtual void Update(float deltaTime);
    virtual void Draw(Camera* pCamera);

    virtual bool IsColliding(GameObject* pOtherGameObject);
    virtual void OnCollision(GameObject* pOtherGameObject);
};

#endif //__GameObject_H__
