// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class GKStarterServerTarget : TargetRules
{
	public GKStarterServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;

		ExtraModuleNames.AddRange(new string[] { "GKStarterGame" });

		GKStarterGameTarget.ApplySharedGKSGTargetSettings(this);

		bUseChecksInShipping = true;
	}
}
