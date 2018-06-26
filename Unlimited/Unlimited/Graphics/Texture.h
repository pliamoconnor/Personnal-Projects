#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
public:
	Texture(const char* file);
	~Texture();

private:
	unsigned int m_TextureID;
};


#endif
