
#include "Graphics.h"
#include "Triangle.h"
#include "Cube.h"


int main()
{
	Graphics* graphics = Graphics::GetGraphicsContext();
	graphics->CreateGraphicsContext();
	
	Triangle* tri = new Triangle(graphics->GetProgramID(), graphics->GetCamera());
	Cube* cub = new Cube(graphics->GetProgramID(), graphics->GetCamera());

	graphics->AddShapeToScene((Shape)*tri);
	graphics->AddShapeToScene((Shape)*cub);
	graphics->BeginDraw();


	delete(tri);
	//delete(triangle2);
	return 0;
}

