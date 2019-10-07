#include "TexturedCube.h"

TexturedCube::TexturedCube(GLuint id) : IGameObject(id)
{
	//108
	vertices = {
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};
	static float g_normal_buffer_data[36 * 3];
	static const GLfloat g_uv_buffer_data[] = {
		0.000059f, 1.0f - 0.000004f,
		0.000103f, 1.0f - 0.336048f,
		0.335973f, 1.0f - 0.335903f,
		1.000023f, 1.0f - 0.000013f,
		0.667979f, 1.0f - 0.335851f,
		0.999958f, 1.0f - 0.336064f,
		0.667979f, 1.0f - 0.335851f,
		0.336024f, 1.0f - 0.671877f,
		0.667969f, 1.0f - 0.671889f,
		1.000023f, 1.0f - 0.000013f,
		0.668104f, 1.0f - 0.000013f,
		0.667979f, 1.0f - 0.335851f,
		0.000059f, 1.0f - 0.000004f,
		0.335973f, 1.0f - 0.335903f,
		0.336098f, 1.0f - 0.000071f,
		0.667979f, 1.0f - 0.335851f,
		0.335973f, 1.0f - 0.335903f,
		0.336024f, 1.0f - 0.671877f,
		1.000004f, 1.0f - 0.671847f,
		0.999958f, 1.0f - 0.336064f,
		0.667979f, 1.0f - 0.335851f,
		0.668104f, 1.0f - 0.000013f,
		0.335973f, 1.0f - 0.335903f,
		0.667979f, 1.0f - 0.335851f,
		0.335973f, 1.0f - 0.335903f,
		0.668104f, 1.0f - 0.000013f,
		0.336098f, 1.0f - 0.000071f,
		0.000103f, 1.0f - 0.336048f,
		0.000004f, 1.0f - 0.671870f,
		0.336024f, 1.0f - 0.671877f,
		0.000103f, 1.0f - 0.336048f,
		0.336024f, 1.0f - 0.671877f,
		0.335973f, 1.0f - 0.335903f,
		0.667969f, 1.0f - 0.671889f,
		1.000004f, 1.0f - 0.671847f,
		0.667979f, 1.0f - 0.335851f
	};

	CalculateNormals(&vertices[0], g_normal_buffer_data);

	//fill the vertex buffer
	FillBuffer("vertexbuffer", &vertices[0], sizeof(vertices) * vertices.size() - 1);
	SetupShaderAttribute("vertexbuffer", 3, GL_FLOAT);
	size = 12 * 3;


	//create and fill other buffers
	CreateBuffer("texture",
		"..//3dcontent//textures//texture_diffuse1.jpg");

	//create uv buffers
	CreateBuffer("uvbuffer");
	FillBuffer("uvbuffer", g_uv_buffer_data, 
		sizeof(g_uv_buffer_data));
	SetupShaderAttribute("uvbuffer", 2, GL_FLOAT);

	///create normal buffer
	CreateBuffer("normalbuffer");
	FillBuffer("normalbuffer", g_normal_buffer_data, 
		sizeof(g_normal_buffer_data));
	SetupShaderAttribute("normalbuffer", 3, GL_FLOAT);

	
	//get uniforms
	GetUniform("MVP");
	GetUniform("M");
	GetUniform("myTextureSampler");
	GetUniform("LightPostionWorldSpace");
	GetUniform("LightDirectionWorldSpace");

}

void TexturedCube::Draw()
{
	//cout << "Doing stuff" << endl;
	glUseProgram(shaderID);
	glBindVertexArray(GetID("vertexarray"));
	glBindBuffer(GL_ARRAY_BUFFER, GetID("vertexbuffer"));

	//send shader uniform data
	glUniformMatrix4fv(GetID("MVP"), 1, GL_FALSE, &MVP[0][0]);

	glDrawArrays(GL_TRIANGLES, 0, size);


	//bind buffers
	glUseProgram(shaderID);
	glBindVertexArray(GetID("vertexarray"));
	glBindBuffer(GL_ARRAY_BUFFER, GetID("vertexbuffer"));
	
	LightDir = glm::normalize(LightPos - glm::vec3(0.0f, 0.0f, 0.0f));

	glUniformMatrix4fv(GetID("MVP"), 1, GL_FALSE, &GetMVP()[0][0]);
	glUniformMatrix4fv(GetID("M"), 1, GL_FALSE, &model[0][0]);
	glUniform3f(GetID("LightDirectionWorldSpace"), LightDir.x, LightDir.y, 
		LightDir.z);
	glUniform3f(GetID("LightPostionWorldSpace"), LightPos.x, LightPos.y,
		LightPos.z);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, GetID("texture"));
	glUniform1i(GetID("myTextureSampler"), 0);
	glDrawArrays(GL_TRIANGLES, 0, size);
}

