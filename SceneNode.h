#pragma once
#include "Header.h"
#include "IComponent.h"
#include "glm.hpp"

class SceneNode : public IComponent
{
public:
	SceneNode();
	~SceneNode();

	// Í¨¹ý IComponent ¼Ì³Ð
	virtual void Start() override;
	virtual void Update() override;
	virtual void Destroy() override;
protected:
	std::vector<std::shared_ptr<IComponent>> m_Components;
	glm::vec3 m_Position;

};

