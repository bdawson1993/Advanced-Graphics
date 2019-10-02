
#include "Graphics.h"
#include "Triangle.h"
#include "Cube.h"


int main()
{

	Graphics* graphics = Graphics::GetGraphicsContext();
	graphics->CreateGraphicsContext();
	
	//create shapes
	Cube* cub = new Cube(graphics->GetCamera(), graphics->GetProgramID());



	

	graphics->AddObjectToScene(cub);
	//graphics->AddShapeToScene((Shape)*cub);
	graphics->BeginDraw();


	delete(cub);
	//delete(triangle2);
	return 0;
}

