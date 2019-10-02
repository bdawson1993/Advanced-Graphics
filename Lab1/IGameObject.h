#pragma once
#include "Shape.h"

class IGameObject : public Shape
{

public:
	IGameObject(WindowCamera& cam) : Shape(cam) {};
	~IGameObject() {} ;

protected:
	virtual void Start() = 0;
	virtual void Update() = 0;
};
