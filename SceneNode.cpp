#include "SceneNode.h"



SceneNode::SceneNode()
{
}


SceneNode::~SceneNode()
{
}

void SceneNode::Start()
{
	for (auto& var : m_Components)
	{
		var->Start();
	}
}

void SceneNode::Update()
{
	for (auto& var : m_Components)
	{
		var->Update();
	}
}

void SceneNode::Destroy()
{
	for (auto& var : m_Components)
	{
		var->Destroy();
	}
}
