// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.


#pragma once

#include "System/LyraGameData.h"

// Unreal Engine
#include "Engine/DataAsset.h"

// Generated
#include "GKSGGameData.generated.h"

class UGameplayEffect;
class UObject;

/**
 * UGKSGGameData
 *
 *	Non-mutable data asset that contains global game data.
 */
UCLASS(BlueprintType, Const, Meta = (DisplayName = "Lyra Game Data", ShortTooltip = "Data asset containing global game data."))
class UGKSGGameData : public ULyraGameData
{
	GENERATED_BODY()

public:

	UGKSGGameData();

	// Returns the loaded game data.
	static const ULyraGameData& Get();

public:

};
