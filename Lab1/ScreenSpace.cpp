#include "ScreenSpace.h"

ScreenSpace::ScreenSpace()
{
	shader = Shader("screenSpace.vertexshader", "screenSpace.fragmentshader");
	SetupVertices();
}

ScreenSpace::~ScreenSpace()
{
}

void ScreenSpace::SetupVertices()
{
	float quadVertices[] = { // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
		   // positions   // texCoords
		   -1.0f,  1.0f,  0.0f, 1.0f,
		   -1.0f, -1.0f,  0.0f, 0.0f,
			1.0f, -1.0f,  1.0f, 0.0f,

		   -1.0f,  1.0f,  0.0f, 1.0f,
			1.0f, -1.0f,  1.0f, 0.0f,
			1.0f,  1.0f,  1.0f, 1.0f
	};


	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
}

void ScreenSpace::Draw(GLuint id)
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// now bind back to default framebuffer and draw a quad plane with the attached framebuffer color texture
	shader.use();
	shader.setInt("screenTexture", 0);
	glBindVertexArray(VAO);

	
	//glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, id);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	//glEnable(GL_DEPTH_TEST);
}
