#pragma once
namespace ZZ {
	class IBehavior
	{
	public:
		virtual int Init() = 0;
		virtual void Exit() = 0;
		virtual void Update() = 0;
	};
}