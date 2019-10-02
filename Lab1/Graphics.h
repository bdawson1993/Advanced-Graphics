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
#include <vector>
#include <random>

#include "Shape.h"
#include "WindowCamera.h"

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
	WindowCamera* cam = new WindowCamera();

	//vector macros
	#define vec3_up glm::vec3(0.0,-0.1,0.0)
	#define vec3_down glm::vec3(0.0,0.1,0.0)
	#define vec3_right glm::vec3(-0.1,0.0,0.0)
	#define vec3_left glm::vec3(0.1,0.0,0.0)
	
public:
	static Graphics* GetGraphicsContext(); //creates or gets window class
	int CreateGraphicsContext();
	void AddShapeToScene(Shape shape);
	//void AddShapeBuffer(const GLfloat vertices[], size_t size);
	int BeginDraw();
	~Graphics();

	//get accesors
	GLuint GetProgramID();
	WindowCamera& GetCamera();


};

