#pragma once
template<class T>
class Singleton
{
public:
	static T& GetInstance()
	{
		static T inst;

	}
protected:
	static T s_Instance;
};

