
#include "Graphics.h"
#include "Triangle.h"
#include "TexturedCube.h"
#include "Cube.h"


int main()
{

	Graphics* graphics = Graphics::GetGraphicsContext();
	graphics->CreateGraphicsContext();


	
	//create shapes
	TexturedCube* cube = new TexturedCube(graphics->GetCamera(), graphics->GetProgramID());
	//Cube* cube = new Cube(graphics->GetCamera(), graphics->GetProgramID());


	graphics->AddObjectToScene(cube);
	//graphics->AddShapeToScene((Shape)*cub);
	graphics->BeginDraw();


	delete(cube);
	//delete(triangle2);
	return 0;
}

