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
#include "WindowCamera.h"

using namespace glm;
using namespace std;

class Shape
{
private:
	//ids
	GLuint vertexArrayID;
	GLuint vertexBufferID;
	GLuint matrixID;
	GLuint programID;
	GLuint colorID;

	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 MVP;
	glm::vec3 color;

public:
	Shape(const GLfloat vertices[], size_t size, GLuint programID, WindowCamera& cam);
	void Translate();
	void Update(glm::mat4* view, glm::mat4* projection);

	//get accessors
	GLuint GetVertexArrayID();
	GLuint GetVertexBufferID();
	GLuint GetProgramID();
	GLuint GetMatrixID();
	GLuint GetColorID();
	glm::mat4 GetMVP();
	glm::vec3 GetColor();

	//set accesors
	void SetColor(float r, float g, float b);
};