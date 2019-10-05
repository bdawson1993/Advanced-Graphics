#pragma once 
#include "IGameObject.h"


class Cube : public IGameObject
{
public:
	Cube(GLuint programId);
	~Cube() {};
	void Draw();

private:

};
