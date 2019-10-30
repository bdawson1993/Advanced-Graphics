#pragma once
#include "Graphics.h"
#include "IGameObject.h"


int main()
{
	
	Graphics* graphics = Graphics::GetGraphicsContext();
	graphics->CreateGraphicsContext();


	IGameObject* mat = new IGameObject("../3dcontent/models/link/scene.gltf",
		"StandardShading");
	mat->SetScale(vec3(0.1));
	mat->SetRotation(glm::quat(sqrt(0.5), -sqrt(0.5), 0, 0));
	
	IGameObject* plane = new IGameObject("../3dcontent/models/plane/plane.fbx",
		"StandardShading");

	
	plane->SetRotation(glm::quat(sqrt(0.5), sqrt(0.5), 0, 0));
	plane->SetPosition(vec3(0, -1, 0));


	
	graphics->AddObjectToScene(plane);
	graphics->AddObjectToScene(mat);
	//graphics->AddObjectToScene(cube);
	graphics->BeginDraw();


	//delete(cube);
	//delete(triangle2);
	return 0;
}

