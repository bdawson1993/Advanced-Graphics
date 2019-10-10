#pragma once
#include "Graphics.h"
#include "IGameObject.h"

int main()
{

	Graphics* graphics = Graphics::GetGraphicsContext();
	graphics->CreateGraphicsContext();


	IGameObject* mat = new IGameObject("../3dcontent/models/mat_scaled/mat_scaled.obj",
		"StandardShading");


	graphics->AddObjectToScene(mat);
	//graphics->AddObjectToScene(cube2);
	graphics->BeginDraw();


	//delete(cube);
	//delete(triangle2);
	return 0;
}

