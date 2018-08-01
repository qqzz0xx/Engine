#pragma once
class IComponent
{
public:
	IComponent();
	~IComponent();
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Destroy() = 0;
};

