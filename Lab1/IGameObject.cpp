#include "IGameObject.h"

void IGameObject::Start()
{
	for (int i = 0; i != componentList.size(); i++)
	{
		componentList[i]->Start();
	}
}

void IGameObject::Update()
{
	for (int i = 0; i != componentList.size(); i++)
	{
		componentList[i]->Update();
	}
}

void IGameObject::Draw()
{
	for (int i = 0; i != componentList.size(); i++)
	{
		componentList[i]->Draw();
	}
}

void IGameObject::AddComponent(Component* comp)
{
	bool exists = false;
	for (int i = 0; i != componentList.size(); i++)
	{
		if (componentList[i]->GetName() == comp->GetName())
		{
			exists == false;
			cout << "Component Already Exists" << endl;
			break;
		}
	}

	


	if (exists == true)
	{
		componentList.push_back(comp);
	}
}

string IGameObject::GetName()
{
	return name;
}

template<typename T>
T& IGameObject::GetComponent(string name)
{
	for (int i = 0; i != componentList.size(); i++)
	{
		if (componentList[i]->GetName() == name)
		{
			return (T*)*componentList[i];
		}
	}
}