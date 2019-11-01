#include "ModelRenderer.h"

ModelRenderer::ModelRenderer(string path, string shaderName) : Component("ModelRenderer")
{
	string vert = shaderName + ".vertexshader";
	string frag = shaderName + ".fragmentshader";
	model = Model(path.c_str());
	shader = Shader(vert.c_str(), frag.c_str());
}

void ModelRenderer::Start()
{
	
}

void ModelRenderer::Draw()
{
	model.Render(Graphics::GetGraphicsContext()->GetCamera().GetView(), 
		Graphics::GetGraphicsContext()->GetCamera().GetProjection(), shader);
}

void ModelRenderer::Update()
{
}

void ModelRenderer::AddTexture(MeshTexture mesh)
{
	model.AddTexture(mesh);
}
