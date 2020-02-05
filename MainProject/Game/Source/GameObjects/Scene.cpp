
#include"GamePCH.h"
#include "Scene.h"
#include"Game.h"
#include"GameObject.h"


//#include "Game.h"

Scene::Scene()
{

    m_pCamera = nullptr;
    m_pGame = nullptr;
    m_pPhysicsWorld = nullptr;

    m_isActive = false;


    //jSonGameObject* JSonGO = nullptr;
   
}

Scene::Scene(Game* pGame, fw::PhysicsWorld* pPhysicsWorld, bool isActive)
{
  //  m_pGame = game;
    m_pCamera = nullptr;
	m_pGame = pGame;
	m_pPhysicsWorld = pPhysicsWorld;
	
	m_isActive = isActive;

   

    
}

Scene::~Scene()
{
   // m_pGame = nullptr;
	//delete m_pGame;
	//delete m_pPhysicsWorld;
}

void Scene::Update(float Delta)
{


}

void Scene::LoadScene(char* filename)
{


    
    long fileLen;
    char* fileContents = fw::LoadCompleteFile(filename, &fileLen);
    cJSON* jRoot = cJSON_Parse(fileContents);

    cJSON* jGameObject = cJSON_GetObjectItem(jRoot, "GameObjects");
    int NumOfGameObject = cJSON_GetArraySize(jGameObject);

    for (int y = 0; y < NumOfGameObject; y++)
    {

        jSonGameObject tempOb;
        cJSON* jRow = cJSON_GetArrayItem(jGameObject, y);
      

        //Set name 
      //  if (y == 0) {
            tempOb.name =cJSON_GetObjectItem(jRow, "Name")->valuestring;

        //}
       // else if (y == 1) {
            cJSON* jpos = cJSON_GetObjectItem(jRow, "Pos");
           
            tempOb.position[0] = cJSON_GetArrayItem(jpos, 0)->valuedouble;
            tempOb.position[1] = cJSON_GetArrayItem(jpos, 1)->valuedouble;
            tempOb.position[2] = cJSON_GetArrayItem(jpos, 2)->valuedouble;
            
           


            

       // }
      

       // else if (y == 2) {
            cJSON* jRot = cJSON_GetObjectItem(jRow, "Rot");

            tempOb.rotation[0] = cJSON_GetArrayItem(jRot, 0)->valuedouble;
            tempOb.rotation[1] = cJSON_GetArrayItem(jRot, 1)->valuedouble;
            tempOb.rotation[2] = cJSON_GetArrayItem(jRot, 2)->valuedouble;


       // }

       // else if (y == 3) {
            cJSON* jScale = cJSON_GetObjectItem(jRow, "Scale");

            tempOb.scale[0] = cJSON_GetArrayItem(jScale, 0)->valuedouble;
            tempOb.scale[1] = cJSON_GetArrayItem(jScale, 1)->valuedouble;
            tempOb.scale[2] = cJSON_GetArrayItem(jScale, 2)->valuedouble;

          

       // }
       // else if (y == 5) {

            
            cJSON* jComponent = cJSON_GetObjectItem(jRow, "Components");
            if (jComponent != nullptr) {
                // tempOb.material = cJSON_GetObjectItem(jComponent, "Material")->valuestring;
                cJSON* jComp1st = cJSON_GetArrayItem(jComponent, 0);
                cJSON* jComp2nd = cJSON_GetArrayItem(jComponent, 1);

                int size1st = cJSON_GetArraySize(jComp1st);
                int size2nd = cJSON_GetArraySize(jComp2nd);


                tempOb.Density = cJSON_GetObjectItem(jComp1st, "Density")->valuedouble;
                tempOb.shape = cJSON_GetObjectItem(jComp1st, "PrimitiveType")->valuestring;
                tempOb.friction = cJSON_GetObjectItem(jComp1st, "Friction")->valuedouble;
                tempOb.Restitution = cJSON_GetObjectItem(jComp1st, "Restitution")->valuedouble;
                tempOb.IsSensor = (bool)cJSON_GetObjectItem(jComp1st, "IsSensor")->valueint;
                tempOb.Static = (bool)cJSON_GetObjectItem(jComp1st, "Static")->valueint;

                tempOb.material = cJSON_GetObjectItem(jComp2nd, "Material")->valuestring;
            }
            


       // }

       // if (tempOb.name == "Player") {

          //  Player* TempPlayer = new Player()

       // }
        std::string a = tempOb.name;
   }
    
}

void Scene::Draw()
{
}
