#pragma once
#include "Components.h"
#include "common/model.h"
#include "SceneManager.h"

class ModelRenderer : public Component
{
public:
	
	ModelRenderer(string path, string shaderName);
	~ModelRenderer() {};

	
	void AddTexture(MeshTexture mesh);

	// Inherited via Component
	virtual void Update() override;

	virtual void Draw() override;

	virtual void Start() override;

private:


protected:
	Model model;
	Shader shader;





	

};
