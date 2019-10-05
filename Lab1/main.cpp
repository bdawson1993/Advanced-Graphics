
#include "Graphics.h"
#include "Triangle.h"
#include "TexturedCube.h"
#include "Cube.h"


int main()
{

	Graphics* graphics = Graphics::GetGraphicsContext();
	graphics->CreateGraphicsContext();


	GLuint id = LoadShaders("basicColor.vertexshader", "basicColor.fragmentshader");
	//create shapes
	TexturedCube* cube = new TexturedCube(graphics->GetProgramID());
	//Cube* cube2 = new Cube(graphics->GetCamera(), id);


	graphics->AddObjectToScene(cube);
	//graphics->AddObjectToScene(cube2);
	graphics->BeginDraw();


	//delete(cube);
	//delete(triangle2);
	return 0;
}

