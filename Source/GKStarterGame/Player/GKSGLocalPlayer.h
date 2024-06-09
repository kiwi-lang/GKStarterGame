// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

// Project
#include "CommonLocalPlayer.h"
#include "GKStarterGame.h"

// Lyra
#include "Player/LyraLocalPlayer.h"
#include "Teams/LyraTeamAgentInterface.h"

// Unreal Engine

// Generated
#include "GKSGLocalPlayer.generated.h"

struct FGenericTeamId;

class APlayerController;
class UInputMappingContext;
class UGKSGSettingsLocal;
class ULyraSettingsShared;
class UObject;
class UWorld;
struct FFrame;
struct FSwapAudioOutputResult;

/**
 * UGKSGLocalPlayer
 */
UCLASS()
class GKSTARTERGAME_API UGKSGLocalPlayer: public ULyraLocalPlayer
{
    GENERATED_BODY()

    public:

};
