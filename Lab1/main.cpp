#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "Graphics.h"
#include "IGameObject.h"
#include "ModelRenderer.h"
#include "SceneManager.h"




int main()
{
	
	Graphics* graphics = Graphics::GetGraphicsContext();
	graphics->CreateGraphicsContext();

	SceneManager* mgr = new SceneManager();



	//create camera object
	IGameObject* cam = new IGameObject("cam", mgr);
	WindowCamera* camera = new WindowCamera();
	cam->AddComponent(camera);

	//create link object
	IGameObject* link = new IGameObject("link", mgr);
	ModelRenderer* linkRender = new ModelRenderer("../3dcontent/models/link/scene.gltf",
		"StandarsShading");
	link->AddComponent(linkRender);
	

	mgr->Add(cam);
	mgr->Add(link);


	/*IGameObject* mat = new IGameObject("../3dcontent/models/link/scene.gltf",
		"StandardShading");
	mat->SetScale(vec3(0.1));
	mat->SetRotation(glm::quat(sqrt(0.5), -sqrt(0.5), 0, 0));
	
	IGameObject* plane = new IGameObject("../3dcontent/models/sea-plane/seaPlane.fbx",
		"wave");
	plane->SetRotation(glm::quat(sqrt(0.5), sqrt(0.5), 0, 0));
	plane->SetPosition(vec3(0, -1, 0));*/

	
	graphics->AddSceneManager(mgr);
	//graphics->AddObjectToScene(mat);

	//graphics->AddObjectToScene(cube);
	graphics->BeginDraw();


	//delete(cube);
	//delete(triangle2);
	return 0;
}

