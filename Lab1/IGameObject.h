#pragma once
#include "Shape.h"

class IGameObject : public Shape
{

public:
	IGameObject(WindowCamera& cam, GLuint programID) : Shape() { camera = &cam; shaderID = programID; };
	~IGameObject() {} ;

public:
	virtual void Start() {};
	virtual void Update() { MVP = camera->GetProjection() * camera->GetView() * model; };
	virtual void Draw() {};
};
