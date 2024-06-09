// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "Modules/ModuleManager.h"


/**
 * FGKStarterGameModule
 */
class FGKStarterGameModule : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
	}

	virtual void ShutdownModule() override
	{
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FGKStarterGameModule, GKStarterGame, "GKStarterGame");
