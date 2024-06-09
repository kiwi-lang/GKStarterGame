// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once


// Lyra
#include "Player/LyraPlayerStart.h"

// Unreal Engine
#include "GameFramework/PlayerStart.h"
#include "GameplayTagContainer.h"
 
// Generated
#include "GKSGPlayerStart.generated.h"


/**
 * AGKSGPlayerStart
 *
 * Base player starts that can be used by a lot of modes.
 */
UCLASS(Config = Game)
class GKSTARTERGAME_API AGKSGPlayerStart: public ALyraPlayerStart
{
    GENERATED_BODY()

};
