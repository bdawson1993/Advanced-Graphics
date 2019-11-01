#pragma once
#include <string>

using namespace std;


class Component
{
public:
	Component(string _name) { _name = name; };
	~Component() {};

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Start() = 0;

	string GetName()
	{
		return name;
	}


private:
	string name;

protected:
	
};


