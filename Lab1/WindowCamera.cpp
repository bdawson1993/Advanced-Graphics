#include "WindowCamera.h"

WindowCamera::WindowCamera()
{
	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

	// Camera matrix
	view = glm::lookAt(
		postion, // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // // Head is up (set to 0,-1,0 to look upside-down)
	);
}

WindowCamera::~WindowCamera()
{
}

void WindowCamera::Translate(vec3 vector)
{
	view = glm::translate(view, vector);
}

glm::mat4 WindowCamera::GetView()
{
	return view;
}

glm::mat4 WindowCamera::GetProjection()
{
	return projection;
}
