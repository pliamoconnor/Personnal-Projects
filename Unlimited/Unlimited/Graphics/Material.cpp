#include "Material.h"
#include "Shader.h"
#include "Texture.h"
#include "Graphics.h"

Material::Material()
{

}

Material::~Material()
{

}

Shader* Material::GetShader()
{
	return m_Shader;
}

Texture* Material::GetTexture()
{
	return m_Texture;
}