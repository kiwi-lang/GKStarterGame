// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

//
#include "System/LyraGameSession.h"

// Unreal Engine
#include "GameFramework/GameSession.h"

// Generated
#include "GKSGGameSession.generated.h"

class UObject;

UCLASS(Config = Game)
class AGKSGGameSession: public ALyraGameSession
{
    GENERATED_BODY()

};
