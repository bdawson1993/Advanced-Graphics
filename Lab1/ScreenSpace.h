#pragma once
#include "common/shader.h"

class ScreenSpace
{
public:
	ScreenSpace();
	~ScreenSpace();
	
	void Draw(GLuint id, GLuint id2);
	void SetupBuffers(int width, int height);

private:
	Shader shader;
	Shader blurShader;
	GLuint VAO;
	GLuint VBO;
	GLuint pingpongFBO[2];
	GLuint pingpongBuffer[2];

	void SetupVertices();
	
};


