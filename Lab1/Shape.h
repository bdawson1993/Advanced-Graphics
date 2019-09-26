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

using namespace glm;

class Shape
{
private:
	GLuint vertexArrayID;
	GLuint vertexBufferID;
	GLuint matrixID;
	glm::mat4 MVP;

public:
	Shape(const GLfloat vertices[], size_t size, int programID);
	GLuint GetVertexArrayID();
	GLuint GetVertexBufferID();
	GLuint GetMatrixID();
	glm::mat4 GetMVP();
	
	

};