// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GKStarterEditorTarget : TargetRules
{
	public GKStarterEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange(new string[] { "GKStarterGame", "GKStarterEditor" });

		if (!bBuildAllModules)
		{
			NativePointerMemberBehaviorOverride = PointerMemberBehavior.Disallow;
		}

		GKStarterGameTarget.ApplySharedGKSGTargetSettings(this);

		// This is used for touch screen development along with the "Unreal Remote 2" app
		EnablePlugins.Add("RemoteSession");
	}
}
