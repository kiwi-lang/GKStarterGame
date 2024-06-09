// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once

// Unreal Engine
#include "Engine/DeveloperSettingsBackedByCVars.h"
#include "UObject/PrimaryAssetId.h"
#include "UObject/SoftObjectPath.h"

// Generated
#include "GKSGDevelopperSettings.generated.h"



/**
 * Developer settings / editor cheats
 */
UCLASS(config = EditorPerProjectUserSettings, MinimalAPI)
class UGKSGDeveloperSettings : public UDeveloperSettingsBackedByCVars
{
	GENERATED_BODY()

};
