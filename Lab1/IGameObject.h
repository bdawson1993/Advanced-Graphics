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

	IGameObject(string _name) { name = _name; };
	~IGameObject() {} ;

	void Start();
	void Update();
	void Draw();

	void AddComponent(Component* comp);

	template <typename T>
	T& GetComponent(string name);


	string GetName();

private:
	string name;
	
protected:
	vector<Component*> componentList;
	
};


