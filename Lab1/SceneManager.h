#pragma once
#include "IGameObject.h"
#include <vector>

using namespace std;
class SceneManager
{
public:
	SceneManager() {};
	~SceneManager() {};

	
	 void Add(IGameObject* gameObject);
	 IGameObject GetGameObject(string name);
	 IGameObject* GetCamera();
	 vector<IGameObject> GetSceneObjects();




private:
	 IGameObject* cam;
	 vector<IGameObject> gameObjects;
};


