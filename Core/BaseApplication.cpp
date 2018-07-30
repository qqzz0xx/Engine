#include "BaseApplication.h"

// Parse command line, read configuration, initialize all sub modules
int ZZ::BaseApplication::Init()
{
	m_bQuit = false;


	return 0;
}


// Finalize all sub modules and clean up all runtime temporary files.
void ZZ::BaseApplication::Exit()
{
	g_pGraphicsManager->Exit();
}


// One cycle of the main loop
void ZZ::BaseApplication::Update()
{
	g_pGraphicsManager->Update();
}

bool ZZ::BaseApplication::IsQuit()
{
	return m_bQuit;
}

