#include "Mesh.h"

Mesh::Mesh(Vector3 position, Vector2 uv, Vector3 normal)
{
	m_VertexData = new VertexFormat(position, uv, normal);
}

Mesh::~Mesh()
{
	if (m_VertexData != nullptr)
	{
		delete m_VertexData;
		m_VertexData = nullptr;
	}
}