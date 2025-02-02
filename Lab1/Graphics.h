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
#include "common/skybox.h"
#include "ScreenSpace.h"


using namespace glm;
using namespace std;

struct TextureIDs
{
	GLuint FBO;
	GLuint textureID;
};


class Graphics
{
private:
	static Graphics* instance;
	Graphics();
	GLFWwindow* window;
	GLuint programID;
	vector<IGameObject*> scenceShapes;
	WindowCamera* cam = new WindowCamera();

	WindowCamera* Lightcam = new WindowCamera();
	WindowCamera* waveCam = new WindowCamera();

	Shader shader;
	Shader screenShader;
	GLuint quadVAO, quadVBO;

	GLFWmonitor* primaryMonitor;
	const GLFWvidmode* mode;
	
	//vector macros
	#define vec3_up glm::vec3(0.0,-0.1,0.0)
	#define vec3_down glm::vec3(0.0,0.1,0.0)
	#define vec3_right glm::vec3(-0.1,0.0,0.0)
	#define vec3_left glm::vec3(0.1,0.0,0.0)
	#define vec3_forward glm::vec3(0,0,-0.1)
	#define vec3_backward glm::vec3(0,0,0.1)


	TextureIDs shadow;
	TextureIDs wave;
	

	
	
public:

	

	static Graphics* GetGraphicsContext(); //creates or gets window class
	int CreateGraphicsContext();
	TextureIDs BuildDepthTexture(GLsizei width, GLsizei height);
	void AddObjectToScene(IGameObject* object);
	int BeginDraw();
	void RenderShadow(glm::vec3& lightPos, TextureIDs mapID, WindowCamera& cam, GLuint cullingMode = GL_BACK);
	~Graphics();

	//get accesors
	GLuint GetProgramID();
	WindowCamera& GetCamera();
	void SetupRenderTargets();
	void DrawQuad();


};


