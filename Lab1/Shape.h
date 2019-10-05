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
#include "ShaderInfo.h"

using namespace glm;
using namespace std;

class Shape : public ShaderInfo
{
private:
	

public:
	Shape();
	void Translate();

	//get accessors
	glm::mat4 GetMVP();
	glm::vec3 GetColor();


	//set accesors
	void SetColor(float r, float g, float b);
	GLsizei GetSize();

protected:
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 MVP;
	glm::vec3 color;
};