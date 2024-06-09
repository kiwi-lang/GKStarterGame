// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

// Lyra
#include "Player/LyraCheatManager.h"

// Unreal Engine
#include "GameFramework/CheatManager.h"

// Generated
#include "GKSGCheatManager.generated.h"


class UGKSGAbilitySystemComponent;

#ifndef USING_CHEAT_MANAGER
#    define USING_CHEAT_MANAGER (1 && !UE_BUILD_SHIPPING)
#endif // #ifndef USING_CHEAT_MANAGER

DECLARE_LOG_CATEGORY_EXTERN(LogGKSGCheat, Log, All);

/**
 * UGKSGCheatManager
 *
 *	Base cheat manager class used by this project.
 */
UCLASS(config = Game, Within = PlayerController, MinimalAPI)
class UGKSGCheatManager: public ULyraCheatManager
{
    GENERATED_BODY()

};
