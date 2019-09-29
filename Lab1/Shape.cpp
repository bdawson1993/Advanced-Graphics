#include "Shape.h"

Shape::Shape(const GLfloat vertices[], size_t size, GLuint programID, glm::mat4* view, glm::mat4* projection)
{
	//setup buffers
	//create a VAO
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	//create a VBO
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	GLuint colorBufferId;
	glGenBuffers(1, &colorBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferId);

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

	// Get a handle for our "MVP" (model * view * projection) uniform
	this->programID = programID;
	matrixID = glGetUniformLocation(programID, "MVP");

	//set up view informatio and compute MVP
	this->view = view;
	this->projection = projection;
	MVP = *this->projection * *this->view * model;
}

void Shape::Translate()
{
	model = glm::translate(model, vec3(0.1f, 0.1f, 0.1f));
	MVP = *this->projection * *this->view * model;
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

//GLuint Shape::GetColorID()
//{
//	return colorID;
//}

glm::mat4 Shape::GetMVP()
{
	return MVP;
}


