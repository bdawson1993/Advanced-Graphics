#pragma once
#include "IGameObject.h"

class TexturedCube : public IGameObject
{
public:
	TexturedCube(GLuint id);
	~TexturedCube() {};
	void Draw();

private:
	glm::vec3 LightPos = glm::vec3(4.0f, 3.0f, 3.0f);
	glm::vec3 LightDir = glm::vec3(0.0f, -1.0f, 0.0f);
};

