#include "OpenGLGraphicsManager.h"
#include "Shader.h"
#include "AssetLoader.h"
#include "Model.h"
#include "glm.hpp"
#include "ext.hpp"
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

	InitGLState();

	shader.LoadByFile("c:\\GameEngineProjects\\Engine\\res\\simple.vs.glsl",
		"c:\\GameEngineProjects\\Engine\\res\\simple.fs.glsl");

	auto image = AssetLoader::LoadImage("container.jpg");
	model.loadModel("Crate1.obj");

	BuildBuffers();
	return 0;
}

void ZZ::OpenGLGraphicsManager::Exit()
{
}

void ZZ::OpenGLGraphicsManager::Update()
{


	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader.Use();

	// view/projection transformations
	glm::mat4 projection = glm::perspective(glm::radians(60.0f), 1.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(0, 10, -50), glm::vec3(), glm::vec3(0,1,0));
	shader.setMat4("projection", projection);
	shader.setMat4("view", view);
	glm::mat4 modelMat;
	modelMat = glm::scale(modelMat, glm::vec3(4.0f));
	shader.setMat4("model", modelMat);
	// render the triangle
	//glBindVertexArray(m_Vao[0].vao);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	model.Draw(shader);
}

void ZZ::OpenGLGraphicsManager::BuildBuffers()
{
	model.BuildBuffer();
	// Allocate an OpenGL vertex array object.
	//GLuint vao;
	//glGenVertexArrays(1, &vao);
	//glBindVertexArray(vao);

	//GLuint vbo[2];
	//glGenBuffers(2, vbo);
	//glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(double) * 3 * 3, triangle.m_Vertices, GL_STATIC_DRAW);
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(double) * 3 * 3, triangle.m_Colors, GL_STATIC_DRAW);
	//glEnableVertexAttribArray(1);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//glBindVertexArray(0);

	//DrawBatchContext ctx
	//{
	//	vao,

	//};

	//m_Vao.emplace_back(ctx);

}

void ZZ::OpenGLGraphicsManager::InitGLState()
{
	glEnable(GL_DEPTH_TEST);

}
