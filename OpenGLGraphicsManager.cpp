#include "OpenGLGraphicsManager.h"
#include "Shader.h"
#include "AssetLoader.h"
#include "Model.h"
#include "glm.hpp"
#include "ext.hpp"
#include "imgui.h"
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

	m_Camera.ComputeProjectionMatrix();
	m_Camera.ComputeViewMatrix();

	BuildBuffers();
	return 0;
}

void ZZ::OpenGLGraphicsManager::Exit()
{
}

void ZZ::OpenGLGraphicsManager::Update()
{
	// Start the ImGui frame

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	m_Camera.Update();
	Draw();
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

void ZZ::OpenGLGraphicsManager::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader.Use();
	shader.setMat4("projection", m_Camera.GetProjectionMatrix());
	shader.setMat4("view", m_Camera.GetViewMatrix());

	glm::mat4 modelMat;
	modelMat = glm::scale(modelMat, glm::vec3(4.0f));
	shader.setMat4("model", modelMat);
	model.Draw(shader);


}
