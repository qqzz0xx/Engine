#include "Triangles.h"

Triangles::Triangles()
{
	m_Vertices = new GLfloat[9]{
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f,
	};
	m_Colors = new GLfloat[9]{
		1.0f, 0.0f, 0.0f,  // Bottom Right
		0.0f, 1.0f, 0.0f,  // Bottom Left
		0.0f, 0.0f, 1.0f   // Top 
	};

}


Triangles::~Triangles()
{
}
