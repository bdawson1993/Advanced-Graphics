#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "Graphics.h"
#include "IGameObject.h"
#include <filesystem>

#include <experimental/filesystem>
using namespace std::experimental::filesystem::v1;


int main()
{

	cout << current_path() << endl;

	
	Graphics* graphics = Graphics::GetGraphicsContext();
	graphics->CreateGraphicsContext();


	IGameObject* mat = new IGameObject("../3dcontent/models/link/scene.gltf",
		"StandardShading");
	mat->SetScale(vec3(0.1));
	mat->SetRotation(glm::quat(sqrt(0.5), -sqrt(0.5), 0, 0));
	
	IGameObject* plane = new IGameObject("../3dcontent/models/sea-plane/seaPlane.fbx",
		"wave");
	plane->SetRotation(glm::quat(sqrt(0.5), sqrt(0.5), 0, 0));
	//plane->SetPosition(vec3(0, -1, 0));

	GLuint waveDisplacement = SOIL_load_OGL_texture(".. /3dcontent/models/sea-plane/displacement.jpg",
		SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB
		| SOIL_FLAG_TEXTURE_REPEATS);
	MeshTexture text;
	text.id = waveDisplacement;
	text.type = "texture_height";
	plane->AddTexture(text);
	


	
	
	
	
	
	
	graphics->AddObjectToScene(plane);
	graphics->AddObjectToScene(mat);

	//graphics->AddObjectToScene(cube);
	graphics->BeginDraw();


	//delete(cube);
	//delete(triangle2);
	return 0;
}