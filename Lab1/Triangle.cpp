#include "Triangle.h"

Triangle::Triangle(GLuint programId, WindowCamera cam) : Shape(1, programId, cam, 3)
{
	static const GLfloat g_vertex_buffer_data[] =
	{
		1.0f,-1.0f, 0.0f,
		-1.0f,-1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f
	};

	FillBuffer("vertexbuffer", g_vertex_buffer_data, 3);
	GetUniform("MVP");
	GetUniform("inColor");
}
