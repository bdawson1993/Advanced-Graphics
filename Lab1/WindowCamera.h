#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;


class WindowCamera
{
public:
	WindowCamera();
	~WindowCamera();

	void Translate(vec3 vector);
	glm::mat4 GetView();
	glm::mat4 GetProjection();

private:
	glm::mat4 view;
	glm::mat4 projection;
};
