#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "Graphics.h"
#include "IGameObject.h"
#include <filesystem>




int main()
{

	Graphics* graphics = Graphics::GetGraphicsContext();
	graphics->CreateGraphicsContext();


	IGameObject* mat = new IGameObject("../3dcontent/models/link/scene.gltf",
		"StandardShading");
	mat->SetScale(vec3(0.1));
	mat->SetRotation(glm::quat(sqrt(0.5), -sqrt(0.5), 0, 0));
	mat->SetPosition(glm::vec3(0, 0, 0.7));
	
	IGameObject* water = new IGameObject("../3dcontent/models/sea-plane/seaPlane.fbx",
		"wave");
	water->SetRotation(glm::quat(sqrt(0.5), sqrt(0.5), 0, 0));
	//plane->SetPosition(vec3(0, 5, 0));

	IGameObject* island = new IGameObject("../3dcontent/models/island/island.fbx",
		"StandardShading");
	island->SetScale(vec3(2));
	island->SetRotation(glm::quat(sqrt(0.5), -sqrt(0.5), 0, 0));
	island->SetPosition(vec3(0, 0, -0.1));

	
	

	graphics->AddObjectToScene(water);


	graphics->AddObjectToScene(island);
	graphics->AddObjectToScene(mat);


	//graphics->AddObjectToScene(cube);
	graphics->BeginDraw();


	//delete(cube);
	//delete(triangle2);
	return 0;
}