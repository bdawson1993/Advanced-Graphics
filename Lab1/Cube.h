#pragma once 
#include "IGameObject.h"


class Cube : public IGameObject
{
public:
	Cube(WindowCamera& cam, GLuint programId);
	~Cube() {};
	void Draw();

private:

};
