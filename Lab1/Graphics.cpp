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
		// Accept fragment if it closer to the camera than the former one
		glDepthFunc(GL_LESS);
		
		
		
		//load basic shader
		programID = LoadShaders("texture.vertexshader", "texture.fragmentshader");
	}
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

int Graphics::BeginDraw()
{
	//scenceShapes[0]->Translate();
	//scenceShapes[0]->SetColor(1.0f, 1.0f, 1.0f);
	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear buffers

		
		//iterare through shapes in scene vector
		for(int i = 0; i != scenceShapes.size(); i++)
		{
			scenceShapes[i]->Draw();
			scenceShapes[i]->Update();
		}
		
		//update logic
		if (glfwGetKey(window, GLFW_KEY_W))
		{
			cam->Translate(vec3_up);
			//scenceShapes[0]->Translate();
		}

		if (glfwGetKey(window, GLFW_KEY_S))
		{
			cam->Translate(vec3_down);
		}

		if (glfwGetKey(window, GLFW_KEY_A))
		{
			cam->Translate(vec3_left);
		}

		if (glfwGetKey(window, GLFW_KEY_D))
		{
			cam->Translate(vec3_right);
		}

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
