
#include"GamePCH.h"
#include "Scene.h"

//#include "Game.h"

Scene::Scene()
{
  //  m_pGame = game;
}

Scene::~Scene()
{
   // m_pGame = nullptr;

}

void Scene::LoadFromFile(const char* filename)
{

    char* contents = fw::LoadCompleteFile(filename, nullptr);
    cJSON* jRoot = cJSON Parse(contents);

    CJSON* jGameObjectArray = cJSON_GetObjectItem(jRoot, "GameObject");
    int numObject = cJson_GetArraySize(jGameObjectArray);
    for (int i = 0; i < numObject; i++) {



    }
    cJSON_Delete(jRoot);
    delete[] contents

}
