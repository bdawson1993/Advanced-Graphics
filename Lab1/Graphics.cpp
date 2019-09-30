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

		// Dark blue background
		glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

		
		
		
		//load basic shader
		programID = LoadShaders("Lab1VertexShader.vertexshader", "Lab1FragmentShader.fragmentshader");
		cout << "Three Mem Address" << endl;
	}
}

void Graphics::AddShapeToScene(Shape shape)
{
	scenceShapes.push_back(shape);
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
	glm::vec3 color = glm::vec3(1.0f, 1.0f, 0.2f);
	scenceShapes[0].Translate();
	scenceShapes[0].SetColor(1.0f, 1.0f, 1.0f);
	int x = 0;
	do {
		glClear(GL_COLOR_BUFFER_BIT); //clear buffers

		//iterare through shapes in scene vector
		vector<Shape>::iterator IT;
		for (IT = scenceShapes.begin(); IT != scenceShapes.end(); IT++)
		{
			//bind needed ID and set program to use
			glBindVertexArray(IT->GetVertexArrayID());
			glBindBuffer(GL_ARRAY_BUFFER, IT->GetVertexBufferID());
			glUseProgram(IT->GetProgramID());

			//send shader uniform data
			glUniformMatrix4fv(IT->GetMatrixID(), 1, GL_FALSE, &IT->GetMVP()[0][0]);
			glUniform3f(IT->GetColorID(), IT->GetColor().r, IT->GetColor().g, IT->GetColor().b);
			
			
			//draw
			glDrawArrays(GL_TRIANGLES, 0, 3);
			IT->Update(&cam->GetView(), &cam->GetProjection());
			
		}
		
		//update
		if (glfwGetKey(window, GLFW_KEY_W))
		{
			//scenceShapes[1].Translate();
			//View = glm::translate(View, vec3(0.0f, 0.1f, 0.0f));
			cam->Translate(vec3_up);
			
		}

		if (glfwGetKey(window, GLFW_KEY_S))
		{
			//scenceShapes[1].Translate();
			//View = glm::translate(View, vec3(0.0f, -0.1f, 0.0f));
			cam->Translate(glm::vec3(0, -0.1, 0.0));
		}

		if (glfwGetKey(window, GLFW_KEY_A))
		{
			//scenceShapes[1].Translate();
			//View = glm::translate(View, vec3(0.0f, -0.1f, 0.0f));
			cam->Translate(vec3_left);
		}

		if (glfwGetKey(window, GLFW_KEY_D))
		{
			//scenceShapes[1].Translate();
			//View = glm::translate(View, vec3(0.0f, -0.1f, 0.0f));
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
