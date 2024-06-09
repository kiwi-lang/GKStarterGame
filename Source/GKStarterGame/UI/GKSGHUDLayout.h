// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#pragma once


//
#include "UI/LyraHUDLayout.h"

// Gamekit
#include "GKSGActivatableWidget.h"

// Unreal Engine

// Generated
#include "GKSGHUDLayout.generated.h"

class UCommonActivatableWidget;
class UObject;

/**
 * UGKSGHUDLayout
 *
 *	Widget used to lay out the player's HUD (typically specified by an Add Widgets action in the experience)
 */
UCLASS(Abstract, BlueprintType, Blueprintable, Meta = (DisplayName = "GKSG HUD Layout", Category = "GKSG|HUD"))
class UGKSGHUDLayout: public ULyraHUDLayout
{
    GENERATED_BODY()

    public:
};
