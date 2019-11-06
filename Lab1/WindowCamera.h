#pragma once


#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW\glfw3.h>

using namespace glm;
using namespace std;


class WindowCamera
{
public:
	WindowCamera();
	~WindowCamera();

	void Rotate(vec3 rotat);
	glm::mat4 GetView();
	glm::mat4 GetProjection();
	void LookAt(vec3 postion, vec3 dir, vec3 down);
	void SetProjection(glm::mat4 proje);
	void Translate(vec3 vector);
	void Update(float deltaTime, double xpos, double ypos, int screenWidth, int screenHeight, int key);

private:
	glm::mat4 view;
	glm::mat4 projection;
	glm::vec3 position = glm::vec3(0, 1, 5);
	glm::vec3 lookingAt = glm::vec3(0, 0, 0);

	// Initial horizontal angle : toward -Z
	float horizontalAngle = 3.14f;
	// Initial vertical angle : none
	float verticalAngle = 0.0f;
	// Initial Field of View
	float initialFoV = 45.0f;

	float speed = 3.0f; // 3 units / second
	float mouseSpeed = 0.015f;


};
