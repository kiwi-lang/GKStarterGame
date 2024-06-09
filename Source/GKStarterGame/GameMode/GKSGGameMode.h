// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.
#pragma once

// GKStaterGame

// Unreal Engine
#include "ModularGameMode.h"

// Generated
#include "GKSGGameMode.generated.h"

class AActor;
class AController;
class AGameModeBase;
class APawn;
class APlayerController;
class UClass;
class UGKSGExperienceDefinition;
class UGKSGPawnData;
class UObject;
struct FFrame;
struct FPrimaryAssetId;
enum class ECommonSessionOnlineMode : uint8;

/**
 * Post login event, triggered when a player or bot joins the game as well as after seamless and non seamless travel
 *
 * This is called after the player has finished initialization
 */
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnGKSGGameModePlayerInitialized,
                                     AGameModeBase * /*GameMode*/,
                                     AController * /*NewPlayer*/);

/**
 * AGKSGGameMode
 *
 *	The base game mode class used by this project.
 */
UCLASS(Config = Game, Meta = (ShortTooltip = "The base game mode class used by this project."))
class AGKSGGameMode: public AModularGameModeBase
{
    GENERATED_BODY()

    public:
};
