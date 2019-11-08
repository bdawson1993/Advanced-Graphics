#include "Graphics.h"

Graphics* Graphics::instance = 0;

Graphics* Graphics::GetGraphicsContext()
{
	if (instance == 0)
	{
		instance = new Graphics();
	}

	return instance;
}

int Graphics::CreateGraphicsContext()
{
	if (instance != 0)
	{
		// Initialise GLFW
		if (!glfwInit())
		{
			fprintf(stderr, "Failed to initialize GLFW\n");
			getchar();
			return -1;

		}

		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		primaryMonitor = glfwGetPrimaryMonitor();
		mode = glfwGetVideoMode(primaryMonitor);

		// Open a window and create its OpenGL context
		window = glfwCreateWindow(mode->width, mode->height, "Test", NULL, NULL);
		if (window == NULL) {
			fprintf(stderr, "Failed to open GLFW window\n");
			getchar();
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);

		// Initialize GLEW
		glewExperimental = true; // Needed for core profile
		if (glewInit() != GLEW_OK) {
			fprintf(stderr, "Failed to initialize GLEW\n");
			getchar();
			glfwTerminate();
			return -1;
		}

		// Ensure we can capture the escape key being pressed below
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

		

		// Dark blue background - and enable depth testing
		glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_STENCIL_TEST);
		// Accept fragment if it closer to the camera than the former one
		glDepthFunc(GL_LESS);
		
		
		
		shader = Shader("depthShader.vertexshader", "depthShader.fragmentshader");
		shadow = BuildDepthTexture(1024 * 2, 1024 * 2);
		wave = BuildDepthTexture(1024 * 2, 1024 * 2);

	}
}

TextureIDs Graphics::BuildDepthTexture(GLsizei width, GLsizei height)
{
	GLuint depthMapFBO = 0;
	GLuint depthMap = 0;


	glGenFramebuffers(1, &depthMapFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);

	glGenTextures(1, &depthMap);
	glBindTexture(GL_TEXTURE_2D, depthMap);

	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthMap, 0);
	glDrawBuffer(GL_NONE);

	TextureIDs depth;
	depth.FBO = depthMapFBO;
	depth.textureID = depthMap;

	return depth;
	
}

//shadow pass
void Graphics::RenderShadow(glm::vec3& lightPos, TextureIDs mapID, WindowCamera& cam, GLuint cullingMode)
{
	//glClear(GL_DEPTH_BUFFER_BIT);
	
	glBindFramebuffer(GL_FRAMEBUFFER, mapID.FBO);
	glViewport(0, 0, 1024 * 2, 1024 * 2);
	glEnable(GL_CULL_FACE);

	glCullFace(cullingMode);

	


	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	//render Shadows
	//iterare through shapes in scene vector
	//glm::mat4 lightProjection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 lightProjection = glm::ortho<float>(-10, 10, -10, 10, -10, 20);
	glm::vec3 lightInvDir = -lightPos;


	cam.LookAt(lightPos,
		lightInvDir, glm::vec3(0.0f,1.0f,0.0f));
	cam.SetProjection(lightProjection);


	//std::reverse(scenceShapes.begin(), scenceShapes.end());
	for (int i = 0; i != scenceShapes.size(); i++)
	{	
		scenceShapes[i]->Draw(&cam, shader);
	}
	//std::reverse(scenceShapes.begin(), scenceShapes.end());

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, mode->width, mode->height);
	glDisable(GL_CULL_FACE);
	
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void Graphics::AddObjectToScene(IGameObject* object)
{
	scenceShapes.push_back(object);
}

GLuint Graphics::GetProgramID()
{
	return programID;
}

WindowCamera& Graphics::GetCamera()
{
	return *cam;
}

GLuint secondTexture = 0;
GLuint frameBuffer = 0;
void Graphics::SetupRenderTargets()
{
	glGenFramebuffers(1, &frameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
	
	glGenTextures(1, &secondTexture);
	glBindTexture(GL_TEXTURE_2D, secondTexture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mode->width, mode->height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, secondTexture, 0);


	GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
	glDrawBuffers(1, DrawBuffers);
}

unsigned int quadVAO, quadVBO;
void Graphics::SetupScreenQuad()
{
	float quadVertices[] = {
		-1.0f,  1.0f,  0.0f, 1.0f,
		-1.0f, -1.0f,  0.0f, 0.0f,
		 1.0f, -1.0f,  1.0f, 0.0f,

		-1.0f,  1.0f,  0.0f, 1.0f,
		 1.0f, -1.0f,  1.0f, 0.0f,
		 1.0f,  1.0f,  1.0f, 1.0f
	};

	
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &quadVBO);
	glBindVertexArray(quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
}

int Graphics::BeginDraw()
{
	//time computations
	double currentTime = glfwGetTime();
	double lastTime = currentTime;
	float deltaTime;
	float timeElapsed = 0;

	//light
	vec3 lightPos = vec3(0, 5, 0);
	vec3 wavepos = vec3(0, 90, 0);
	

	//create light to show in lights position
	IGameObject* light = new IGameObject("../3dcontent/models/sphere/sphere.fbx",
		"basicColor");
	light->SetScale(vec3(0.2));

	
	//setup skybox shader and obj
	Shader skyboxShader("skybox.vertexshader", "skybox.fragmentshader");
	Skybox sky("../3dcontent/skybox/tropicalsunnyday/", "TropicalSunnyDayRight.png", "TropicalSunnyDayLeft.png", "TropicalSunnyDayUp.png", "TropicalSunnyDayDown.png", "TropicalSunnyDayBack.png", "TropicalSunnyDayFront.png");
	
	//create texture for second target and setup shader
	Shader screenShader("screenSpace.vertexshader", "screenSpace.fragmentshader");

	
	SetupRenderTargets();


	//add depth textures to the models
	//render scene
	for (int i = 0; i != scenceShapes.size(); i++)
	{


		MeshTexture shadowt;
		shadowt.id = shadow.textureID;
		shadowt.type = "shadow_map";

		MeshTexture wavet;
		wavet.id = wave.textureID;
		wavet.type = "shadow_map";



		scenceShapes[i]->AddTexture(shadowt);
		scenceShapes[i]->AddTexture(wavet);

	}


	//scenceShapes[0]->Translate();
	//scenceShapes[0]->SetColor(1.0f, 1.0f, 1.0f);
	float scale = 2.015;

	//start rendering
	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear buffers

		//compute delta time
		currentTime = glfwGetTime();
		deltaTime = float(currentTime - lastTime);
		timeElapsed += deltaTime;




		//shadow pass
		RenderShadow(lightPos, shadow, *Lightcam, GL_FRONT);
		//float result = std::abs(std::remainder(timeElapsed * 0.5, 2.1 * 1));
		//cout << result  << endl;

		//border pass
		if (scale >= 2.002)
		{
			scale -= 0.01 * deltaTime;
		}
		else
		{
			
			scale = 2.015;
		}
		


		//waveCam->LookAt(vec3(0, 0, 0), vec3(0, 90, 0), vec3(0, 1, 0));
		scenceShapes[1]->SetScale(vec3(scale));
		RenderShadow(vec3(0, 90, 0), wave, *waveCam);
		scenceShapes[1]->SetScale(vec3(2));



		//render scene
		glm::mat4 biasMatrix(
			0.5, 0.0, 0.0, 0.0,
			0.0, 0.5, 0.0, 0.0,
			0.0, 0.0, 0.5, 0.0,
			0.5, 0.5, 0.5, 1.0
		);



		//glm::mat4 lightProjection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
		//glm::mat4 lightProjection = glm::ortho<float>(-10, 10, -10, 10, -10, 20);

		//glm::mat4 shadowMatrix =  lightProjection * Lightcam.GetView();
		glm::mat4 shadowMatrix = glm::mat4(biasMatrix * Lightcam->GetProjection() * Lightcam->GetView());
		glm::mat4 waveMatrix = glm::mat4(biasMatrix  * waveCam->GetProjection() * waveCam->GetView());


		glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
		//glActiveTexture(GL_TEXTURE0 + 4);
		//glBindTexture(GL_TEXTURE_2D, secondColorTexture);
		sky.Draw(cam->GetView(), cam->GetProjection(), skyboxShader);
		for (int i = 0; i != scenceShapes.size(); i++)
		{
			scenceShapes[i]->shader.use();
			scenceShapes[i]->shader.setVec3("lightPos", lightPos);
		
			scenceShapes[i]->shader.setMat4("shadowMatrix", shadowMatrix);
			scenceShapes[i]->shader.setMat4("waveMatrix", waveMatrix);

			scenceShapes[i]->Draw(cam);

		}
		light->shader.use();
		light->SetPosition(lightPos);
		light->Draw(cam);

		//screen space - effects
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // set clear color to white (not really necessery actually, since we won't be able to see behind the quad anyways)
		glClear(GL_COLOR_BUFFER_BIT);
		glDisable(GL_DEPTH_TEST);


		screenShader.use();

		glBindVertexArray(quadVAO);
		
		//glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, secondTexture);
		screenShader.setInt("screenTexture", 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		//update logic
#pragma region
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		if (glfwGetKey(window, GLFW_KEY_W))
		{
			cam->Update(deltaTime, xpos, ypos, mode->width, mode->height, GLFW_KEY_W);
			glfwSetCursorPos(window, mode->width / 2, mode->height / 2);

		}

		if (glfwGetKey(window, GLFW_KEY_S))
		{
			cam->Update(deltaTime, xpos, ypos, mode->width, mode->height, GLFW_KEY_S);
			glfwSetCursorPos(window, mode->width / 2, mode->height / 2);
		}

		if (glfwGetKey(window, GLFW_KEY_A))
		{
			cam->Update(deltaTime, xpos, ypos, mode->width, mode->height, GLFW_KEY_A);
			glfwSetCursorPos(window, mode->width / 2, mode->height / 2);
		}

		if (glfwGetKey(window, GLFW_KEY_D))
		{
			cam->Update(deltaTime, xpos, ypos, mode->width, mode->height, GLFW_KEY_D);
			glfwSetCursorPos(window, mode->width / 2, mode->height / 2);

		}



		if (glfwGetKey(window, GLFW_KEY_LEFT))
		{
			lightPos += vec3_right;


		}

		if (glfwGetKey(window, GLFW_KEY_RIGHT))
		{
			lightPos += vec3_left;
		}


		if (glfwGetKey(window, GLFW_KEY_UP))
		{
			lightPos += vec3_forward;

		}

		if (glfwGetKey(window, GLFW_KEY_DOWN))
		{
			lightPos += vec3_backward;

		}

		

#pragma endregion Cam_Update

			//cout << pos.x << " " << pos.y << " " << pos.z << endl;
			lastTime = currentTime;
			//cout << deltaTime << endl;

			// Swap buffers
			
			glfwSwapBuffers(window);
			glfwPollEvents();

		} // Check if the ESC key was pressed or the window was closed
		while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(window) == 0);


		// Close OpenGL window and terminate GLFW
		glfwTerminate();



		return 0;
}




Graphics::~Graphics()
{
	delete(window);
	delete(instance);
}

Graphics::Graphics()
{
	

}