#include "Shape.h"

Shape::Shape() : ShaderInfo::ShaderInfo()
{

}

void Shape::Translate()
{
	model = glm::translate(model, vec3(0.1f, 0.1f, 0.1f));
	
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


