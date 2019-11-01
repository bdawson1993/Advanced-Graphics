#pragma once
#include "Components.h"
#include "common/model.h"

class ModelRenderer : public Component
{
public:
	
	ModelRenderer(string path, string shaderName);
	~ModelRenderer() {};

	void Start();
	void Draw();
	void Update();
	void AddTexture(MeshTexture mesh);

private:


protected:
	Model model;
	Shader shader;




};
