#pragma once
#include <map>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <SOIL2.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "WindowCamera.h"

using namespace std;
using namespace glm;



class ShaderInfo
{
public:
		ShaderInfo();
		~ShaderInfo() {};
		GLuint GetID(string name);
		GLuint GetProgramID();
		

private:
	map<string, GLuint> ids;
	GLuint currentAttId = 0;
	GLuint currentBoundId = 0;

protected:
	GLuint shaderID = 0;
	GLsizei size = 3;
	WindowCamera* camera;

	void CreateBuffer(string name);
	void CreateBuffer(string name, string path);

	void FillBuffer(string name, const GLfloat data[], size_t size);


	void GetUniform(string name);
	void SetupShaderAttribute(string bufferName, GLuint size, GLenum type);
	void ListIds();
	void CalculateNormals(const GLfloat* vertices, float* normalbuffer);
	

};