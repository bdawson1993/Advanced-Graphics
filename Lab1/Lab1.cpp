
#include "Graphics.h"

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

	static const GLfloat g_vertex_buffer_data2[] =
	{
		2.0f, -1.0f,0.0f,
		-1.0f,-1.0f, 0.0f,
		-1.0f, 1.0f,0.0f
	};

	graphics->AddShapeBuffer(g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	graphics->AddShapeBuffer(g_vertex_buffer_data2, sizeof(g_vertex_buffer_data));


	graphics->Draw();
}

