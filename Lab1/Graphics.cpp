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


		// Open a window and create its OpenGL context
		window = glfwCreateWindow(1024, 768, "Test", NULL, NULL);
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
		
		
		
		//load basic shader
		// TODO: you should create a PhongSpec lighting model in these shaders
		shader = Shader("depthShader.vertexshader", "depthShader.fragmentshader");
		BuildShadowTexture(1024,1024);

	}
}

void Graphics::BuildShadowTexture(GLsizei width, GLsizei height)
{
	glGenFramebuffers(1, &depthMapFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);

	glGenTextures(1, &depthMap);
	glBindTexture(GL_TEXTURE_2D, depthMap);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthMap, 0);
	glDrawBuffer(GL_NONE);
	

	//GLfloat border[] = { 1.0f,0.0f,0.0f,0.0f };

	//glGenTextures(1, &depthID);
	//glBindTexture(GL_TEXTURE_2D, depthID);
	//glTexStorage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width, height);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	////glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LESS);

	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, depthID);


	//glGenFramebuffers(1, &shadowFBO);
	//glBindFramebuffer(GL_FRAMEBUFFER, shadowFBO);
	//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthID, 0);
	//glDrawBuffer(GL_NONE);
	//glReadBuffer(GL_NONE);


	//GLenum drawBuffers[] = { GL_NONE };
	//glDrawBuffers(1,drawBuffers);
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Graphics::RenderShadow(glm::vec3& lightPos, glm::vec3& amint)
{
	glBindFramebuffer(GL_FRAMEBUFFER, depthMap);
	glViewport(0, 0, 1024, 1024);
	glEnable(GL_CULL_FACE);

	glCullFace(GL_BACK);


	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	

	//render Shadows
	//iterare through shapes in scene vector
	glm::mat4 lightProjection = glm::ortho<float>(-10, 10, -10, 10, -10, 20);
	glm::vec3 lightInvDir = glm::vec3(0.5f, 2, 2);

	//glm::mat4 depthBiasMVP = biasMatrix * depthMVP;


	WindowCamera Lightcam = WindowCamera();
	Lightcam.LookAt(lightPos,
		lightPos -lightInvDir, glm::vec3(0.0f,1.0f,0.0f));
	Lightcam.SetProjection(lightProjection);

	for (int i = 0; i != scenceShapes.size(); i++)
	{
		scenceShapes[i]->Draw(&Lightcam, shader);
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, 1024, 768);
	glDisable(GL_CULL_FACE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

}

void Graphics::AddObjectToScene(IGameObject* object)
{
	//bind shadow
	MeshTexture text;
	text.id = depthMap;
	text.type = "shadow_map";

	object->AddTexture(text);
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

int Graphics::BeginDraw()
{
	vec3 lightPos = vec3(0.5, 20, 20);
	vec3 amint = vec3(0.1);

	//scenceShapes[0]->Translate();
	//scenceShapes[0]->SetColor(1.0f, 1.0f, 1.0f);
	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear buffers
		
		RenderShadow(lightPos, amint);
		glm::mat4 biasMatrix(
			0.5, 0.0, 0.0, 0.0,
			0.0, 0.5, 0.0, 0.0,
			0.0, 0.0, 0.5, 0.0,
			0.5, 0.5, 0.5, 1.0
		);
		
		//render scene
		for (int i = 0; i != scenceShapes.size(); i++)
		{
			scenceShapes[i]->shader.setVec3("lightPos", lightPos);
			scenceShapes[i]->shader.setVec3("ambint", amint);
			scenceShapes[i]->shader.setMat4("depthBias", biasMatrix);
			scenceShapes[i]->Draw(cam);
			scenceShapes[i]->Update();
		}



		

		
		//update logic
#pragma region
		if (glfwGetKey(window, GLFW_KEY_W))
		{
			cam->Translate(vec3_forward);
		}

		if (glfwGetKey(window, GLFW_KEY_S))
		{
			cam->Translate(vec3_backward);
		}

		if (glfwGetKey(window, GLFW_KEY_A))
		{
			cam->Translate(vec3_left);
		}

		if (glfwGetKey(window, GLFW_KEY_D))
		{
			cam->Translate(vec3_right);
			
		}

		if (glfwGetKey(window, GLFW_KEY_Q))
		{
			cam->Rotate(vec3_left);
		}

		if (glfwGetKey(window, GLFW_KEY_E))
		{
			cam->Rotate(vec3_right);
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
			lightPos += vec3_down;
		}

		if (glfwGetKey(window, GLFW_KEY_DOWN))
		{
			lightPos += vec3_up;
		}

		if (glfwGetKey(window, GLFW_KEY_I))
		{
			amint += vec3(0.1);
			cout << amint.x << " "  << amint.y << " " << amint.z << endl;
		}

		if (glfwGetKey(window, GLFW_KEY_K))
		{
			amint -= vec3(0.1);
			cout << amint.x << " " << amint.y << " " << amint.z << endl;
		}

		

#pragma endregion Cam_Update

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
