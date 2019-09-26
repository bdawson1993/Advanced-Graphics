
#include "Graphics.h"
#include "Shape.h"

int main( void )
{
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

	Shape* triangle = new Shape(g_vertex_buffer_data, sizeof(g_vertex_buffer_data), graphics->GetProgramID());
	Shape* triangle2 = new Shape(g_vertex_buffer_data2, sizeof(g_vertex_buffer_data2), graphics->GetProgramID());

	//graphics->AddShapeBuffer(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	graphics->AddShapeToScene(*triangle);
	graphics->AddShapeToScene(*triangle2);

	graphics->BeginDraw();
}

