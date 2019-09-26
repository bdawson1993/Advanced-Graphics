#include "Shape.h"

Shape::Shape(const GLfloat vertices[], size_t size, int programID)
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
	matrixID = glGetUniformLocation(programID, "MVP");

	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(0, 0, 6), // Camera is at (0,0,6), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around

}

GLuint Shape::GetVertexArrayID()
{
	return vertexArrayID;
}

GLuint Shape::GetVertexBufferID()
{
	return vertexBufferID;
}

GLuint Shape::GetMatrixID()
{
	return matrixID;
}

glm::mat4 Shape::GetMVP()
{
	return MVP;
}
