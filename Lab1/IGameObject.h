#pragma once
#include "Shape.h"

class IGameObject : public Shape
{

public:
	IGameObject(GLuint programID) : Shape() {shaderID = programID; };
	~IGameObject() {} ;

public:
	virtual void Start(WindowCamera& cam) { camera = &cam; };
	virtual void Update() { 
		MVP = camera->GetProjection() * camera->GetView() * model;  
	};
	virtual void Draw() {};
};
