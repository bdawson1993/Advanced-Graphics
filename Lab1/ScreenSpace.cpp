#include "ScreenSpace.h"
 
//implmented based on -- https://learnopengl.com/Advanced-Lighting/Bloom

ScreenSpace::ScreenSpace()
{
	shader = Shader("screenSpace.vertexshader", "screenSpace.fragmentshader");
	blurShader = Shader("screenSpace.vertexshader", "bloom.fragmentshader");
	SetupVertices();

}

ScreenSpace::~ScreenSpace()
{
}

void ScreenSpace::SetupVertices()
{
	float quadVertices[] = { 
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

void ScreenSpace::SetupBuffers(int width, int height)
{
	//create buffer for the blur
	glGenFramebuffers(2, pingpongFBO);
	glGenTextures(2, pingpongBuffer);
	GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0 };


	glBindFramebuffer(GL_FRAMEBUFFER, pingpongFBO[0]);
	glBindTexture(GL_TEXTURE_2D, pingpongBuffer[0]);
	glTexImage2D(
		GL_TEXTURE_2D, 0, GL_RGB16F, width, height, 0, GL_RGB, GL_FLOAT, NULL
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(
		GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, pingpongBuffer[0], 0
	);


	glDrawBuffers(1, DrawBuffers);

	glBindFramebuffer(GL_FRAMEBUFFER, pingpongFBO[1]);
	glBindTexture(GL_TEXTURE_2D, pingpongBuffer[1]);
	glTexImage2D(
		GL_TEXTURE_2D, 0, GL_RGB16F, width, height, 0, GL_RGB, GL_FLOAT, NULL
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(
		GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, pingpongBuffer[1], 0
	);


	glDrawBuffers(1, DrawBuffers);


}

void ScreenSpace::Draw(GLuint id, GLuint id2)
{

	//first blur pass
	blurShader.use();
	glBindFramebuffer(GL_FRAMEBUFFER, pingpongFBO[0]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	blurShader.setInt("horizontal", true);
	blurShader.setInt("image", 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, id2);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	//second blur pass
	glBindFramebuffer(GL_FRAMEBUFFER, pingpongFBO[1]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	blurShader.setInt("horizontal", false);
	blurShader.setInt("image", 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, pingpongBuffer[0]);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);





	//finally render the scene
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// now bind back to default framebuffer and draw a quad plane with the attached framebuffer color texture
	shader.use();
	shader.setInt("screenTexture", 0);
	shader.setInt("screenTexture2", 1);
	glBindVertexArray(VAO);


	//glDisable(GL_DEPTH_TEST);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, id);

	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, pingpongBuffer[1]);

	glDrawArrays(GL_TRIANGLES, 0, 6);
	//glEnable(GL_DEPTH_TEST);
}
