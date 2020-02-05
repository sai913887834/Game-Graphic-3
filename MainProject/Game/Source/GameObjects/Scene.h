
#ifndef __Scene_H__
#define __Scene_H__
//class Game;

class Game;
class Camera;
class Player;
class GameObject;
class Scene {
    struct jSonGameObject {

        std::string name;
        double position[3];
        double rotation[3];
        double scale[3];
        //std::string flag;
        std::string material;
        std::string shape;
        bool Static;
        float Density;
        bool IsSensor;
        double friction;
        double Restitution;


    };


public:
	Scene();
    Scene(Game* pGame, fw::PhysicsWorld* pPhysicsWorld, bool isActive = false);
      ~Scene();
    virtual void Update(float Delta);
    virtual void LoadScene(char* filename) ;
    virtual void Draw() ;

protected:

    Game* m_pGame;
	fw::PhysicsWorld* m_pPhysicsWorld;
	bool m_isActive ;
	Camera* m_pCamera;
	//Player* m_pPlayer;
	std::vector<GameObject*> m_GameObjects;
   
	




};
#endif //__Scene_H__