#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

// we're using shaders so need this for the "LoadShaders" function
#include <common/shader.hpp>

class Graphics
{
private:
	static Graphics* instance;
	Graphics();
	GLFWwindow* window;

public:
	static Graphics* GetGraphicsContext(); //creates or gets window class
	void Draw();
	~Graphics();


};

