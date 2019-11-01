#pragma once
#include "WindowCamera.h"
#include "common/model.h"
#include "common/shader.h"
#include "common/GLError.h"
#include <iostream>


using namespace std;

class IGameObject : public Model
{
public:

	Shader shader;

	//Path - path of the model to load
	//shader name - the name of the shader to load. must be like 
	//shaderName.fragmentshader, shaderName.vertexshader on the disk to be
	//loaded correctly
	IGameObject(const string path, string shaderName) : Model(path) 
	{
		//load shader
		string vert = shaderName + ".vertexshader";
		string frag = shaderName + ".fragmentshader";
		cout << "Compiling..." << shaderName << endl;
		shader = Shader(vert.c_str(), frag.c_str());
	};

	~IGameObject() {} ;

public:
	
	virtual void Start() {
	
	};

	virtual void Update() { 
		
	};

	virtual void Draw(WindowCamera* cam) {
		Render(cam->GetView(), cam->GetProjection(), shader);
	};

	virtual void Draw(WindowCamera* cam, Shader shad)
	{
		Render(cam->GetView(), cam->GetProjection(), shad);
	};

protected:
	
};