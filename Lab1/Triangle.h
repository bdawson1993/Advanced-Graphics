#pragma once
#include "IGameObject.h"

class Triangle : public IGameObject
{

public:
	Triangle(WindowCamera& cam,GLuint programId);
};
