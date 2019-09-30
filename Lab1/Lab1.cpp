
#include "Graphics.h"
#include "Shape.h"

int main( void )
{
	int* x = new int();
	*x = 10;
	int& y = *x;


	*x =+ 1;
	cout << *x << " " << y << endl;


	Graphics* graphics = Graphics::GetGraphicsContext();
	if (graphics->CreateGraphicsContext() == -1)
	{
		return -1;
	}

	static const GLfloat g_vertex_buffer_data[] =
	{
		1.0f,-1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		-2.0f, 1.0f, 0.0f

	};

	static const GLfloat g_vertex_buffer_data2[] =
	{
		1.0f,-1.0f, 0.0f,
		-1.0f,-1.0f, 0.0f,
-		1.0f, 1.0f, 0.0f

	};

	Shape* triangle = new Shape(g_vertex_buffer_data, sizeof(g_vertex_buffer_data), graphics->GetProgramID(), graphics->GetCamera());
	Shape* triangle2 = new Shape(g_vertex_buffer_data2, sizeof(g_vertex_buffer_data2), graphics->GetProgramID(), graphics->GetCamera());

	//graphics->AddShapeBuffer(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	graphics->AddShapeToScene(*triangle);
	graphics->AddShapeToScene(*triangle2);

	graphics->BeginDraw();




	delete(triangle);
	delete(triangle2);
}

