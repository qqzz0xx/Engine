#include "OpenGLGraphicsManager.h"

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

	return 0;
}

void ZZ::OpenGLGraphicsManager::Exit()
{
}

void ZZ::OpenGLGraphicsManager::Update()
{

}
