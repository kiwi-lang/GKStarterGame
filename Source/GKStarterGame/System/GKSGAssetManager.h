// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once


// Gamekit 

// Lyra
#include "System/LyraAssetManagerStartupJob.h"
#include "System/LyraAssetManager.h"

// Unreal Engine
#include "Engine/AssetManager.h"
#include "Templates/SubclassOf.h"

// Generated
#include "GKSGAssetManager.generated.h"


/**
 * UGKSGAssetManager
 *
 *	Game implementation of the asset manager that overrides functionality and stores game-specific types.
 *	It is expected that most games will want to override AssetManager as it provides a good place for game-specific
 *loading logic. This class is used by setting 'AssetManagerClassName' in DefaultEngine.ini.
 */
UCLASS(Config = Game)
class UGKSGAssetManager: public ULyraAssetManager
{
    GENERATED_BODY()

    public:
 
};
