// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

// Lyra
#include "UI/LyraHUD.h"

// Unreal Engine

// Generated
#include "GKSGHUD.generated.h"

class UCommonActivatableWidget;
class UObject;

/**
 * UGKSGHUD
 *
 *	Widget used to lay out the player's HUD (typically specified by an Add Widgets action in the experience)
 */
UCLASS(Abstract, BlueprintType, Blueprintable, Meta = (DisplayName = "GKSG HUD Layout", Category = "GKSG|HUD"))
class AGKSGHUD: public ALyraHUD
{
    GENERATED_BODY()

};
