#include "Camera.h"
#include "Camera.h"
#include "Camera.h"
#include "Camera.h"
#include "AppConfig.h"

namespace ZZ {
	extern AppConfig* g_pAppConfig;
}

using namespace ZZ;

Camera::Camera()
{
	pos = glm::vec3(0, 10, -50);
	up = glm::vec3(0, 1, 0);
	fov = 60;
	znear = 0.03f;
	zfar = 300.0f;
}


Camera::~Camera()
{
}

void Camera::ComputeViewMatrix()
{
	m_ViewMatrix = glm::lookAt(pos, target, up);
}

void Camera::ComputeProjectionMatrix()
{
	float aspect = float(g_pAppConfig->screenWidth) / g_pAppConfig->screenWidth;

	m_ProjectionMatrix = glm::perspective(glm::radians(fov), aspect, znear, zfar);
}

void Camera::Start()
{

}

void Camera::Update()
{
	auto a = glm::rotate(pos, 0.1f, up);
	pos = glm::vec3(a.x, a.y, a.z);
	ComputeViewMatrix();
}

void Camera::Destroy()
{
}
