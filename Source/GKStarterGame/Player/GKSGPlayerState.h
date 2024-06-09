// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once


// Lyra
#include "Player/LyraPlayerState.h"
#include "Teams/LyraTeamAgentInterface.h"

// Unreal Engine
#include "AbilitySystemInterface.h"
#include "ModularPlayerState.h"
#include "System/GameplayTagStack.h"



// Generated
#include "GKSGPlayerState.generated.h"

/**
 * AGKSGPlayerState
 *
 *	Base player state class used by this project.
 */
UCLASS(Config = Game)
class GKSTARTERGAME_API AGKSGPlayerState: public ALyraPlayerState
{
    GENERATED_BODY()
};
