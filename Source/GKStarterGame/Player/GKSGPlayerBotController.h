// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

#include "ModularAIController.h"

// Lyra
#include "Teams/LyraTeamAgentInterface.h"
#include "Player/LyraPlayerBotController.h"

// Generated
#include "GKSGPlayerBotController.generated.h"

namespace ETeamAttitude
{
enum Type : int;
}
struct FGenericTeamId;

class APlayerState;
class UAIPerceptionComponent;
class UObject;
struct FFrame;

/**
 * AGKSGPlayerBotController
 *
 *	The controller class used by player bots in this project.
 */
UCLASS(Blueprintable)
class AGKSGPlayerBotController: public ALyraPlayerBotController
{
    GENERATED_BODY()

    public:

};
