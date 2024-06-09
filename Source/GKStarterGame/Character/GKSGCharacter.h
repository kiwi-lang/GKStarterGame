// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once


// Lyra
#include "Teams/LyraTeamAgentInterface.h"

// Unreal Engine
#include "AbilitySystemInterface.h"
#include "GameplayCueInterface.h"
#include "GameplayTagAssetInterface.h"
#include "ModularCharacter.h"


// Generated
#include "GKSGCharacter.generated.h"


/**
 * AGKSGCharacter
 *
 *	The base character pawn class used by this project.
 *	Responsible for sending events to pawn components.
 *	New behavior should be added via pawn components when possible.
 */
UCLASS(Config = Game, Meta = (ShortTooltip = "The base character pawn class used by this project."))
class GKSTARTERGAME_API AGKSGCharacter : public AModularCharacter //, public IAbilitySystemInterface, public IGameplayCueInterface, public IGameplayTagAssetInterface, public IGKSGTeamAgentInterface
{
	GENERATED_BODY()

public:
};