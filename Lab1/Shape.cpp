#include "Shape.h"

Shape::Shape(WindowCamera& cam, GLsizei count) : ShaderInfo::ShaderInfo()
{
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

GLsizei Shape::GetSize()
{
	return size;
}


