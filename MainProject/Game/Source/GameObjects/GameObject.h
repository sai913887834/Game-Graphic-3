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
    vec3 m_rotation;
    vec3 m_Scale;
    float m_Radius;
	fw::PhysicsBody* m_pBody;

    std::string shape;
    bool Static;
    float Density;
    bool IsSensor;
    double friction;
    double Restitution;


 

public:
    GameObject(Game* pGame, Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec3 position);
    ~GameObject();

    vec3 GetPosition() { return m_Position; }
    vec3 GetRotation() { return m_rotation; }
    vec3 GetScale() { return m_Scale; }
    std::string GetShape() { return shape; }
    bool GetIsStatic() { return Static; }
    float GetDensity() { return Density; }
    bool GetIsSensor() { return IsSensor; }
    double GetFriction() { return friction; }
    double GetRestitution() { return Restitution; }


    void SetPosition(vec3 position) { m_Position = position; }
    void SetRotation(vec3 rotation) { m_rotation = rotation; }
    void SetScale(vec3 scale) { m_Scale = scale; }

    void SetShape(std::string pshape) { shape = pshape; }
    void SetIsStatic(bool isStatic) {  Static = isStatic; }
    void SetDensity(float density) {  Density = density; }
    void SetIsSensor(bool sensor) {  IsSensor = sensor; }
    void SetFriction(double fric) {  friction = fric; }
    void SetRestitution(double restitution) {Restitution = restitution; }

    float GetRadius() { return m_Radius; }

    //void SetPosition(vec3 pos) { m_Position = pos; }

    virtual void Update(float deltaTime);
    virtual void Draw(Camera* pCamera);

    virtual bool IsColliding(GameObject* pOtherGameObject);
    virtual void OnCollision(GameObject* pOtherGameObject);
	virtual void AddBox(vec3 size, vec3 offset);
};

#endif //__GameObject_H__
