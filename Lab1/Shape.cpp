#include "Shape.h"

Shape::Shape(const GLfloat vertices[], size_t size, GLuint programID, WindowCamera& cam)
{
	//setup buffers
	//create a VAO
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	//create a VBO
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	//fill VBO with data
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	

	//setup shader
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0, // attribute index
		3, // size
		GL_FLOAT, // type
		GL_FALSE, // normalized?
		0, // stride
		(void*)0 // array buffer offset
	);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1, // attribute index
		3, // size
		GL_FLOAT, // type
		GL_FALSE, // normalized?
		0, // stride
		(void*)0 // array buffer offset
	);

	// Get a handle for our "MVP" (model * view * projection) uniform
	this->programID = programID;
	matrixID = glGetUniformLocation(programID, "MVP");
	colorID = glGetUniformLocation(programID, "inColor");


	//set up view information and compute MVP
	MVP = cam.GetProjection() * cam.GetView() * model;

}

void Shape::Translate()
{
	model = glm::translate(model, vec3(0.1f, 0.1f, 0.1f));
	
}

void Shape::Update(glm::mat4* view, glm::mat4* projection)
{
	MVP = MVP = *projection * *view * model;
}

GLuint Shape::GetVertexArrayID()
{
	return vertexArrayID;
}

GLuint Shape::GetVertexBufferID()
{
	return vertexBufferID;
}

GLuint Shape::GetProgramID()
{
	return programID;
}

GLuint Shape::GetMatrixID()
{
	return matrixID;
}

GLuint Shape::GetColorID()
{
	return colorID;
}

glm::mat4 Shape::GetMVP()
{
	return MVP;
}

glm::vec3 Shape::GetColor()
{
	return color;
}

void Shape::SetColor(float r, float g, float b)
{
	color = glm::vec3(r, g, b);
}


