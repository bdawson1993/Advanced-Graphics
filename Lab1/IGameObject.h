#pragma once
#include "WindowCamera.h"
#include "common/model.h"
#include "common/shader.h"
#include "common/GLError.h"
#include <iostream>
#include "Components.h"
#include <vector>

using namespace std;

class IGameObject
{
public:
	
	Shader shader;

	IGameObject()
	{
		
	};

	~IGameObject() {} ;

public:
	
	void Start();

	void Update();

	void Draw();

	void AddComponent(Component* comp);

	template <typename T>
	T& GetComponent(string name);


protected:
	vector<Component*> componentList;
	
};


