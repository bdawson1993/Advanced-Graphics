#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <common/shader.hpp>

using namespace glm;
using namespace std;

class Shape
{
private:
	GLuint vertexArrayID;
	GLuint vertexBufferID;
	GLuint matrixID;
	GLuint programID;

public:
	Shape(const GLfloat vertices[], size_t size, GLuint programID);
	GLuint GetVertexArrayID();
	GLuint GetVertexBufferID();
	GLuint GetProgramID();
	GLuint GetMatrixID();
};