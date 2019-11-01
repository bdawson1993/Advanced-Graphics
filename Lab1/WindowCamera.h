#pragma once

#include "Components.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;
using namespace std;


class WindowCamera : public Component
{
public:
	WindowCamera();
	~WindowCamera();

	void Translate(vec3 vector);
	void Rotate(vec3 rotat);
	glm::mat4 GetView();
	glm::mat4 GetProjection();
	void LookAt(vec3 postion, vec3 dir, vec3 down);
	void SetProjection(glm::mat4 proje);

	virtual void Update() override;
	virtual void Draw() override;
	virtual void Start() override;

private:
	glm::mat4 view;
	glm::mat4 projection;
	glm::vec3 position = glm::vec3(4, 3, 3);
	glm::vec3 lookingAt = glm::vec3(0, 0, 0);

};
