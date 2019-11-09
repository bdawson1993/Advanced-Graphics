#pragma once
#include "common/shader.h"

class ScreenSpace
{
public:
	ScreenSpace();
	~ScreenSpace();
	void Draw(GLuint id);

private:
	Shader shader;
	GLuint VAO;
	GLuint VBO;

	void SetupVertices();
	
};


