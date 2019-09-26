#include "Shape.h"

Shape::Shape(const GLfloat vertices[], size_t size, GLuint programID)
{
	//create a VAO
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	//create a VBO
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	//fill VBO with data
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

	//setup vertewx attribute pointers
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


