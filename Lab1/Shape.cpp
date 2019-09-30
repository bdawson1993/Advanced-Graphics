#include "Shape.h"

Shape::Shape(const GLfloat vertices[], size_t size, GLuint programID, WindowCamera& cam) : ShaderInfo::ShaderInfo(programID)
{
	//fill buffer with data
	FillBuffer("vertexbuffer", vertices, size);

	//set up shader attributes
	SetupShaderAttribute("vertexbuffer", 3, GL_FLOAT);
	this->programID = programID;

	//get uniforms
	GetUniform("MVP");
	GetUniform("inColor");


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


GLuint Shape::GetProgramID()
{
	return programID;
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


