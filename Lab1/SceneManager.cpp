#include "SceneManager.h"

void SceneManager::Add(IGameObject* gameObject)
{
	if (gameObject->GetName() == "cam")
	{
		cam = gameObject;
	}
	else
	{
		gameObjects.push_back(*gameObject);
	}


}

IGameObject SceneManager::GetGameObject(string name)
{
	vector<IGameObject>::iterator it;
	for (it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		if (it->GetName() == name)
		{
			return *it;
		}
	}

	return NULL;
}

IGameObject* SceneManager::GetCamera()
{
	return cam;
}

vector<IGameObject> SceneManager::GetSceneObjects()
{
	return gameObjects;
}
