#ifndef MATERIAL_H
#define MATERIAL_H

class Shader;
class Texture;

class Material
{
public:
	Material();
	~Material();

	Shader* GetShader();
	Texture* GetTexture();

private:
	Shader* m_Shader;
	Texture* m_Texture;
};

#endif