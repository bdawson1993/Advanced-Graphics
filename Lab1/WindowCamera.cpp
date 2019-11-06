#include "WindowCamera.h"


WindowCamera::WindowCamera()
{
	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

	// Camera matrix
	view = glm::lookAt(
		position, // Camera is at (4,3,3), in World Space
		lookingAt, // and looks at the origin
		glm::vec3(0, 1, 0)  // // Head is up (set to 0,-1,0 to look upside-down)
	);
}

WindowCamera::~WindowCamera()
{
}



void WindowCamera::Rotate(vec3 rotat)
{


	lookingAt = lookingAt + rotat;
	// Camera matrix
	view = glm::lookAt(
		position, // Camera is at (4,3,3), in World Space
		lookingAt, // and looks at the origin
		glm::vec3(0, 1, 0)  // // Head is up (set to 0,-1,0 to look upside-down)
	);
}

glm::mat4 WindowCamera::GetView()
{
	return view;
}

glm::mat4 WindowCamera::GetProjection()
{
	return projection;
}

void WindowCamera::LookAt(vec3 postion, vec3 dir, vec3 down)
{
	view = glm::lookAt(
		position,
		dir,
		down
	);

	this->position = position;
	this->lookingAt = dir;



}

void WindowCamera::SetProjection(glm::mat4 proje)
{
	projection = proje;
}

void WindowCamera::Translate(vec3 vector)
{
	position += vector;
	lookingAt += vector;
	view = glm::lookAt(
		position, // Camera is at (4,3,3), in World Space
		lookingAt, // and looks at the origin
		glm::vec3(0, 1, 0)  // // Head is up (set to 0,-1,0 to look upside-down)
	);
}

void WindowCamera::Update(float deltaTime, double xpos, double ypos, int screenWidth, int screenHeight, int key)
{
	// Compute new orientation
	horizontalAngle += mouseSpeed * float(screenWidth / 2 - xpos);
	verticalAngle += mouseSpeed * float(screenHeight / 2 - ypos);

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);

	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f)
	);

	// Up vector
	glm::vec3 up = glm::cross(right, direction);

	// Move forward
	if (key == GLFW_KEY_W) {
		cout << key << endl;
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (key == GLFW_KEY_S) {
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (key == GLFW_KEY_A) {
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (key == GLFW_KEY_D) {
		position -= right * deltaTime * speed;
	}

	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	projection = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	view = glm::lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
	);


}


