#pragma once
#
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "Shape.h"

using namespace glm;
using namespace std;

// we're using shaders so need this for the "LoadShaders" function
#include <common/shader.hpp>

class Graphics
{
private:
	static Graphics* instance;
	Graphics();
	GLFWwindow* window;
	GLuint programID;
	vector<Shape> scenceShapes;

	GLuint MatrixID;
	glm::mat4 MVP;

public:
	static Graphics* GetGraphicsContext(); //creates or gets window class
	int CreateGraphicsContext();
	void AddShapeToScene(Shape shape);
	//void AddShapeBuffer(const GLfloat vertices[], size_t size);
	GLuint GetProgramID();
	int Draw();
	~Graphics();


};

