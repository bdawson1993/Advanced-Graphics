#include "ShaderInfo.h"

//create the basic VAO and VBO
ShaderInfo::ShaderInfo(GLuint shaderID)
{
	//create VAO
	GLuint vertexID;
	glGenVertexArrays(1, &vertexID);
	ids.insert(pair<string, GLuint>("vertexarray", vertexID));
	glBindVertexArray(vertexID);

	//create a VBO
	GLuint vertesBufferID;
	glGenBuffers(1, &vertesBufferID);
	ids.insert(pair<string, GLuint>("vertexbuffer", vertesBufferID));
	glBindBuffer(GL_ARRAY_BUFFER, vertesBufferID);
	currentBoundId = vertesBufferID;


	this->shaderId = shaderID;
}

//create a new buffer
void ShaderInfo::CreateBuffer(string name)
{
	GLuint id;
	glGenBuffers(1, &id);
	ids.insert(pair<string, GLuint>(name, id));
}

//bind the named bind and fill it with data
void ShaderInfo::FillBuffer(string name, const GLfloat data[], size_t size)
{
	//prevent binding current bound buffer
	glBindBuffer(GL_ARRAY_BUFFER, GetID(name));
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

//Get the id of a uniform from the shader
void ShaderInfo::GetUniform(string name)
{
	GLuint id = glGetUniformLocation(shaderId, name.c_str());
	ids.insert(pair<string, GLuint>(name, id));
}

//Create a new Shader attribe  
void ShaderInfo::SetupShaderAttribute(string bufferName, GLuint size, GLenum type)
{
	glBindBuffer(GL_ARRAY_BUFFER, GetID(bufferName));
	glEnableVertexAttribArray(currentAttId);
	glVertexAttribPointer(
		currentAttId, // attribute index
		size, // size
		type, // type
		GL_FALSE, // normalized?
		0, // stride
		(void*)0 // array buffer offset
	);
	currentAttId++;

}

void ShaderInfo::ListIds()
{
	for (std::map<string, GLuint>::iterator it = ids.begin(); it != ids.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

GLuint ShaderInfo::GetID(string name)
{
	return ids.find(name)->second;
}
