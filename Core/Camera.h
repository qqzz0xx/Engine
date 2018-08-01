#pragma once
#include "Header.h"
#include "IComponent.h"
class Camera : public IComponent
{
public:
	Camera();
	~Camera();



	void ComputeViewMatrix();
	void ComputeProjectionMatrix();

	glm::mat4 GetViewMatrix() { return m_ViewMatrix; }
	glm::mat4 GetProjectionMatrix() { return m_ProjectionMatrix; }

	// Í¨¹ý IComponent ¼Ì³Ð
	virtual void Start() override;
	virtual void Update() override;
	virtual void Destroy() override;

private:
	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ProjectionMatrix;

	glm::vec3 pos;
	glm::vec3 target;
	glm::vec3 up;
	float fov;
	float zfar;
	float znear;

};

