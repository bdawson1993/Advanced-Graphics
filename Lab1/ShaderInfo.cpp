#include "ShaderInfo.h"
#include "Graphics.h"

//create the basic VAO and VBO
ShaderInfo::ShaderInfo()
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

	Graphics* grap = Graphics::GetGraphicsContext();
	camera = &grap->GetCamera();
	
}

//create a new buffer
void ShaderInfo::CreateBuffer(string name)
{
	GLuint id;
	glGenBuffers(1, &id);
	ids.insert(pair<string, GLuint>(name, id));
	glBindBuffer(GL_ARRAY_BUFFER, id);
	currentBoundId = id;
	
}

//create texture buffer
void ShaderInfo::CreateBuffer(string name, string path)
{
	GLuint id = SOIL_load_OGL_texture(path.c_str(), 
		SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | 
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB);

	ids.insert(pair<string, GLuint>(name, id));
}

//bind the named buffer and fill it with data
void ShaderInfo::FillBuffer(string name, const GLfloat data[], size_t size)
{
	//bind if buffer is not currently bound -- prevents rebounding
	GLuint id = GetID(name);
	if (id != currentBoundId)
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
		currentBoundId = id;
	}

	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

//Get the id of a uniform from the shader
void ShaderInfo::GetUniform(string name)
{
	GLuint id = glGetUniformLocation(shaderID, name.c_str());
	ids.insert(pair<string, GLuint>(name, id));
}

//Create a new Shader attribe  
void ShaderInfo::SetupShaderAttribute(string bufferName, GLuint size, GLenum type)
{
	//bind if buffer is not currently bound -- prevents rebounding
	GLuint id = GetID(bufferName);
	if (id != currentBoundId)
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
		currentBoundId = id;
	}

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

void ShaderInfo::CalculateNormals(const GLfloat* vertices, float* normalbuffer)
{
	unsigned int output = 0;
	unsigned int input = 0;

	for (unsigned int i = 0; i < 12; i++)
	{
		// first vertex
		glm::vec3 vertex1(vertices[input + 0], vertices[input + 1], vertices[input + 2]);
		// second vertex
		glm::vec3 vertex2(vertices[input + 3], vertices[input + 4], vertices[input + 5]);
		// third vertex
		glm::vec3 vertex3(vertices[input + 6], vertices[input + 7], vertices[input + 8]);
		// the "stride" of the input.. 3 floats each for 3 vertices = 9 floats total
		input += 9;

		// line between our first vertex and our second
		glm::vec3 v1tov2(glm::normalize(vertex2 - vertex1));
		// line between our first vertex and our third
		glm::vec3 v1tov3(glm::normalize(vertex3 - vertex1));
		// cross product to give us the normal (note we normalize the two input vectors first)
		glm::vec3 normal(glm::cross(v1tov2, v1tov3));
		// normalize the resultant normal (shouldn't be needed, but I'm paranoid)
		normal = normalize(normal);
		// write our three vertices worth of normal with the same value (i.e. a flat face with all vertex normals pointing the same way)
		normalbuffer[output + 0] = normal.x;
		normalbuffer[output + 1] = normal.y;
		normalbuffer[output + 2] = normal.z;
		normalbuffer[output + 3] = normal.x;
		normalbuffer[output + 4] = normal.y;
		normalbuffer[output + 5] = normal.z;
		normalbuffer[output + 6] = normal.x;
		normalbuffer[output + 7] = normal.y;
		normalbuffer[output + 8] = normal.z;
		// stride of the output, 3x3 = 9 same as input as it happens!!
		output += 9;

	}
}

GLuint ShaderInfo::GetID(string name)
{
	return ids.find(name)->second;
}

GLuint ShaderInfo::GetProgramID()
{
	return shaderID;
}


