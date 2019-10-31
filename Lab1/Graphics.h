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
#include "IGameObject.h"
#include "WindowCamera.h"
#include "SOIL2.h"
// the code for both of these is adapted from examples on LearnOpenGL.com
#include "common/model.h"
#include "common/shader.h"
// can't remember where this comes from.. there are lots of examples on the internet of similar code
#include "common/GLError.h"

using namespace glm;
using namespace std;

class Graphics
{
private:
	static Graphics* instance;
	Graphics();
	GLFWwindow* window;
	GLuint programID;
	vector<IGameObject*> scenceShapes;
	WindowCamera* cam = new WindowCamera();
	WindowCamera Lightcam = WindowCamera();
	Shader shader;

	
	//vector macros
	#define vec3_up glm::vec3(0.0,-0.1,0.0)
	#define vec3_down glm::vec3(0.0,0.1,0.0)
	#define vec3_right glm::vec3(-0.1,0.0,0.0)
	#define vec3_left glm::vec3(0.1,0.0,0.0)
	#define vec3_forward glm::vec3(0,0,-0.1)
	#define vec3_backward glm::vec3(0,0,0.1)
	GLuint depthMap;
	GLuint depthMapFBO;
	GLuint waveDisplacement;
	
public:
	static Graphics* GetGraphicsContext(); //creates or gets window class
	int CreateGraphicsContext();
	void BuildShadowTexture(GLsizei width, GLsizei height);
	void AddObjectToScene(IGameObject* object);
	//void AddShapeBuffer(const GLfloat vertices[], size_t size);
	int BeginDraw();
	void RenderShadow(glm::vec3& lightPos, glm::vec3& amint);
	~Graphics();

	//get accesors
	GLuint GetProgramID();
	WindowCamera& GetCamera();


};

