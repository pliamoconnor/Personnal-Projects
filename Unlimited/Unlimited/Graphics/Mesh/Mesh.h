#ifndef MESH_H
#define MESH_H

#include "Math/Vector.h"
#include "Graphics\Graphics.h"

struct VertexFormat
{
	Vector3 pos;
	Vector2 uv;
	Vector3 normal;

	VertexFormat(Vector3 apos, Vector2 auv, Vector3 anormal)
	{
		pos = apos;
		uv = auv;
		normal = anormal;
	}
};


class Mesh
{
public:
	Mesh(Vector3 position, Vector2 uv, Vector3 normals);
	~Mesh();

private:
	VertexFormat* m_VertexData;

	GLuint m_VBO;
	GLuint m_IBO;
};

#endif
