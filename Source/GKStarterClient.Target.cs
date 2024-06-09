// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GKStarterClientTarget : TargetRules
{
	public GKStarterClientTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Client;

		ExtraModuleNames.AddRange(new string[] { "GKStarterGame" });

		GKStarterGameTarget.ApplySharedGKSGTargetSettings(this);
	}
}
