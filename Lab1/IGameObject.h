#pragma once
#include "Shape.h"

class IGameObject : public Shape
{

public:
	IGameObject(Shape shape) : Shape(shape) {};
	~IGameObject() {} ;

protected:
	virtual void Start() = 0;
	virtual void Update() = 0;
};
