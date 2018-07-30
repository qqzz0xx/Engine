#include "OpenGLGraphicsManager.h"
#include "Shader.h"
#include "Image.h"
#include <iostream>
using namespace std;

int ZZ::OpenGLGraphicsManager::Init()
{
	int hr;
	hr = gladLoadGL();
	if (!hr)
	{
		cout << "init opengl failed!" << endl;
	}
	else
	{
		cout << "OpenGL Version " << GLVersion.major << "." << GLVersion.minor << " loaded" << endl;
	}


	shader.LoadByFile("f:\\Engine\\res\\simple.vs.glsl", "f:\\Engine\\res\\simple.fs.glsl");
	BuildBuffers();

	int width, height, nrChannels;
	unsigned char *data = stbi_load("f:\\Engine\\res\\container.jpg", &width, &height, &nrChannels, 0);
	Image image("container.jpg");

	return 0;
}

void ZZ::OpenGLGraphicsManager::Exit()
{
}

void ZZ::OpenGLGraphicsManager::Update()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	shader.Use();
	// render the triangle
	glBindVertexArray(m_Vao[0].vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void ZZ::OpenGLGraphicsManager::BuildBuffers()
{
	// Allocate an OpenGL vertex array object.
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo[2];
	glGenBuffers(2, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(double) * 3 * 3, triangle.m_Vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(double) * 3 * 3, triangle.m_Colors, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);

	DrawBatchContext ctx
	{
		vao,

	};

	m_Vao.emplace_back(ctx);

}
