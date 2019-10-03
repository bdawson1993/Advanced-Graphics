#pragma once
#include "IGameObject.h"
#include "SOIL2.h"

class TexturedCube : public IGameObject
{
public:
	TexturedCube(WindowCamera cam, GLuint id);
	~TexturedCube() {};
	void Draw();

private:

};

