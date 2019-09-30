#pragma once
#include <map>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

using namespace std;

class ShaderInfo
{
public:
		ShaderInfo(GLuint shaderID);
		~ShaderInfo() {};
		GLuint GetID(string name);

private:
	map<string, GLuint> ids;
	GLuint currentAttId = 0;
	GLuint shaderId;
	GLuint currentBoundId;

protected:
	void CreateBuffer(string name);
	void FillBuffer(string name, const GLfloat data[], size_t size);
	void GetUniform(string name);
	void SetupShaderAttribute(string bufferName, GLuint size, GLenum type);
	void ListIds();
	

	


};