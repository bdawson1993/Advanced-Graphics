#pragma once



#include "Graphics.h"
#include "IGameObject.h"





int main()
{

	Graphics* graphics = Graphics::GetGraphicsContext();
	graphics->CreateGraphicsContext();


	IGameObject* link = new IGameObject("../3dcontent/models/link/scene.gltf",
		"toon");
	link->SetScale(vec3(0.1));
	link->SetRotation(glm::quat(sqrt(0.5), -sqrt(0.5), 0, 0));
	link->SetPosition(glm::vec3(0, 0, 0.8));
	
	IGameObject* water = new IGameObject("../3dcontent/models/sea-plane/seaPlane.fbx",
		"water");
	water->SetRotation(glm::quat(sqrt(0.5), sqrt(0.5), 0, 0));
	//plane->SetPosition(vec3(0, 5, 0));
	water->SetScale(vec3(12));

	IGameObject* island = new IGameObject("../3dcontent/models/island/island.fbx",
		"toon");
	island->SetScale(vec3(2));
	island->SetRotation(glm::quat(sqrt(0.5), -sqrt(0.5), 0, 0));
	island->SetPosition(vec3(0, 0, -0.1));

	IGameObject* tree = new IGameObject("../3dcontent/models/tree/scene.gltf",
		"toon");
	tree->SetPosition(vec3(6, 0.0, 0.4));
	//tree->SetScale(vec3(0.1));
	tree->SetRotation(glm::quat(sqrt(0.5), -sqrt(0.5), 0, 0));

	


	

	

	
	

	

	graphics->AddObjectToScene(water);
	graphics->AddObjectToScene(island);
	graphics->AddObjectToScene(link);
	graphics->AddObjectToScene(tree);
	
	
	
	
	graphics->BeginDraw();


	//delete(cube);
	//delete(triangle2);
	return 0;
}