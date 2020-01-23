
#ifndef __Scene_H__
#define __Scene_H__
//class Game;
class Scene {
public:
    Scene();
      ~Scene();
    virtual void Update(float Delta) = 0;
    virtual void Init() = 0;
    virtual void Draw() = 0;
    void LoadFromFile(const char* filename);

private:

    //Game* m_pGame;



};
#endif //__Scene_H__