// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

// Include
#include "GKSGGameData.h"

// Project
#include "System/GKSGAssetManager.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GKSGGameData)

UGKSGGameData::UGKSGGameData()
{
}

const ULyraGameData& UGKSGGameData::UGKSGGameData::Get()
{
	return UGKSGAssetManager::Get().GetGameData();
}
