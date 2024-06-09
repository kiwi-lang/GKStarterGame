// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "GKStarterEditorEngine.h"

// #include "Development/GKStarterDeveloperSettings.h"
// #include "Development/GKStarterPlatformEmulationSettings.h"
// #include "GameModes/GKStarterWorldSettings.h"

#include "Engine/GameInstance.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Settings/ContentBrowserSettings.h"
#include "Settings/LevelEditorPlaySettings.h"
#include "Widgets/Notifications/SNotificationList.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(GKStarterEditorEngine)

class IEngineLoop;

#define LOCTEXT_NAMESPACE "GKStarterEditor"

UGKStarterEditorEngine::UGKStarterEditorEngine(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGKStarterEditorEngine::Init(IEngineLoop* InEngineLoop)
{
	Super::Init(InEngineLoop);
}

void UGKStarterEditorEngine::Start()
{
	Super::Start();
}

void UGKStarterEditorEngine::Tick(float DeltaSeconds, bool bIdleMode)
{
	Super::Tick(DeltaSeconds, bIdleMode);
	
	FirstTickSetup();
}

void UGKStarterEditorEngine::FirstTickSetup()
{
#if 0
	if (bFirstTickSetup)
	{
		return;
	}

	bFirstTickSetup = true;

	// Force show plugin content on load.
	GetMutableDefault<UContentBrowserSettings>()->SetDisplayPluginFolders(true);
#endif

}

FGameInstancePIEResult UGKStarterEditorEngine::PreCreatePIEInstances(const bool bAnyBlueprintErrors, const bool bStartInSpectatorMode, const float PIEStartTime, const bool bSupportsOnlinePIE, int32& InNumOnlinePIEInstances)
{
#if 0
	if (const AGKStarterWorldSettings* GKStarterWorldSettings = Cast<AGKStarterWorldSettings>(EditorWorld->GetWorldSettings()))
	{
		if (GKStarterWorldSettings->ForceStandaloneNetMode)
		{
			EPlayNetMode OutPlayNetMode;
			PlaySessionRequest->EditorPlaySettings->GetPlayNetMode(OutPlayNetMode);
			if (OutPlayNetMode != PIE_Standalone)
			{
				PlaySessionRequest->EditorPlaySettings->SetPlayNetMode(PIE_Standalone);

				FNotificationInfo Info(LOCTEXT("ForcingStandaloneForFrontend", "Forcing NetMode: Standalone for the Frontend"));
				Info.ExpireDuration = 2.0f;
				FSlateNotificationManager::Get().AddNotification(Info);
			}
		}
	}

	//@TODO: Should add delegates that a *non-editor* module could bind to for PIE start/stop instead of poking directly
	GetDefault<UGKStarterDeveloperSettings>()->OnPlayInEditorStarted();
	GetDefault<UGKStarterPlatformEmulationSettings>()->OnPlayInEditorStarted();

#endif
	//
	FGameInstancePIEResult Result = Super::PreCreatePIEServerInstance(bAnyBlueprintErrors, bStartInSpectatorMode, PIEStartTime, bSupportsOnlinePIE, InNumOnlinePIEInstances);

	return Result;
}

#undef LOCTEXT_NAMESPACE
