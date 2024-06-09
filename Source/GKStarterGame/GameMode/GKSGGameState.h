// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

// GKStaterGame


// Lyra
#include "GameModes/LyraGameState.h"

// Unreal Engine
#include "AbilitySystemInterface.h"
#include "ModularGameState.h"

// Generated
#include "GKSGGameState.generated.h"

struct FGKSGVerbMessage;

class APlayerState;
class UAbilitySystemComponent;
class UGKSGAbilitySystemComponent;
class UGKSGExperienceManagerComponent;
class UObject;
struct FFrame;

/**
 * AGKSGGameState
 *
 *	The base game state class used by this project.
 */
UCLASS(Config = Game)
class GKSTARTERGAME_API AGKSGGameState: public ALyraGameState
{
    GENERATED_BODY()

    public:
};
