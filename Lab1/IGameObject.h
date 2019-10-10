#pragma once
#include "WindowCamera.h"
#include "common/model.h"
#include "common/shader.h"
#include "common/GLError.h"

class IGameObject : public Model
{
public:
	//Path - path of the model to load
	//shader name - the name of the shader to load. must be like 
	//shaderName.fragmentshader, shaderName.vertexshader on the disk to be
	//loaded correctly
	IGameObject(const string path, string shaderName) : Model(path) 
	{
		//load shader
		string vert = shaderName + ".vertexshader";
		string frag = shaderName + ".fragmentshader";
		shader = Shader(vert.c_str(), frag.c_str());
	};

	~IGameObject() {} ;

public:
	virtual void Start() {
	
	};

	virtual void Update() { 
		
	};

	virtual void Draw(WindowCamera* cam) {
		shader.use();
		Render(cam->GetView(), cam->GetProjection(), shader);
	};

protected:
	Shader shader;
};
