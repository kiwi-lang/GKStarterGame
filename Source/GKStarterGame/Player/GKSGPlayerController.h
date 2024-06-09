// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once


// Gamekit
#include "CommonPlayerController.h"

// Lyra
#include "Camera/LyraCameraAssistInterface.h"
#include "Player/LyraPlayerController.h"
#include "Teams/LyraTeamAgentInterface.h"


// Generated
#include "GKSGPlayerController.generated.h"

struct FGenericTeamId;

class AGKSGHUD;
class AGKSGPlayerState;
class APawn;
class APlayerState;
class FPrimitiveComponentId;
class IInputInterface;
class UGKSGAbilitySystemComponent;
class UGKSGSettingsShared;
class UObject;
class UPlayer;
struct FFrame;

/**
 * AGKSGPlayerController
 *
 *	The base player controller class used by this project.
 */
UCLASS(Config = Game, Meta = (ShortTooltip = "The base player controller class used by this project."))
class GKSTARTERGAME_API AGKSGPlayerController: public ALyraPlayerController
{
    GENERATED_BODY()

};

// A player controller used for replay capture and playback
UCLASS()
class AGKSGReplayPlayerController: public ALyraReplayPlayerController
{
    GENERATED_BODY()
};
