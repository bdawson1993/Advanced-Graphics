#include "Triangle.h"

Triangle::Triangle(GLuint programId, WindowCamera cam) : Shape(cam, 3)
{
	shaderID = programId;
	static const GLfloat g_vertex_buffer_data[] =
	{
		1.0f,-1.0f, 0.0f,
		-1.0f,-1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f
	};
	FillBuffer("vertexbuffer", g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	SetupShaderAttribute("vertexbuffer", 3, GL_FLOAT);

	Shape::size = sizeof(g_vertex_buffer_data);

	
	
	GetUniform("MVP");
	GetUniform("inColor");

	SetColor(1, 1, 1);
}
