
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
		1.0f, -1.0f,0.0f,
		-1.0f,-1.0f, 0.0f,
		-1.0f, 1.0f,0.0f
	};

	Shape triangle = Shape(g_vertex_buffer_data, sizeof(g_vertex_buffer_data), graphics->GetProgramID());


	//graphics->AddShapeBuffer(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	graphics->AddShapeToScene(triangle);

	graphics->Draw();
}

