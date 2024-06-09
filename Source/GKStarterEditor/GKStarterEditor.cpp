// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

#include "GKStarterEditor.h"


// #include "Development/GKStarterDeveloperSettings.h"
// #include "GameEditorStyle.h"
// #include "GameModes/GKStarterExperienceManager.h"
// #include "Private/AssetTypeActions_GKStarterContextEffectsLibrary.h"
// #include "Validation/EditorValidator.h"

#include "AbilitySystemGlobals.h"
#include "DataValidationModule.h"
#include "Editor/UnrealEdEngine.h"
#include "Engine/GameInstance.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "IAssetTypeActions.h"
#include "GameplayAbilitiesEditorModule.h"
#include "GameplayCueInterface.h"
#include "GameplayCueNotify_Burst.h"
#include "GameplayCueNotify_BurstLatent.h"
#include "GameplayCueNotify_Looping.h"

#include "ToolMenu.h"
#include "ToolMenus.h"
#include "UObject/UObjectIterator.h"
#include "UnrealEdGlobals.h"


class SWidget;

#define LOCTEXT_NAMESPACE "GKStarterEditor"

DEFINE_LOG_CATEGORY(LogGKStarterEditor);

// This function tells the GameplayCue editor what classes to expose when creating new notifies.
static void GetGameplayCueDefaultClasses(TArray<UClass*>& Classes)
{
	Classes.Empty();
	Classes.Add(UGameplayCueNotify_Burst::StaticClass());
	Classes.Add(AGameplayCueNotify_BurstLatent::StaticClass());
	Classes.Add(AGameplayCueNotify_Looping::StaticClass());
}

// This function tells the GameplayCue editor what classes to search for GameplayCue events.
static void GetGameplayCueInterfaceClasses(TArray<UClass*>& Classes)
{
	Classes.Empty();

	for (UClass* Class : TObjectRange<UClass>())
	{
		if (Class->IsChildOf<AActor>() && Class->ImplementsInterface(UGameplayCueInterface::StaticClass()))
		{
			Classes.Add(Class);
		}
	}
}

// This function tells the GameplayCue editor where to create the GameplayCue notifies based on their tag.
static FString GetGameplayCuePath(FString GameplayCueTag)
{
#if 0
	FString Path = FString(TEXT("/Game"));

	//@TODO: Try plugins (e.g., GameplayCue.ShooterGame.Foo should be in ShooterCore or something)

	// Default path to the first entry in the UAbilitySystemGlobals::GameplayCueNotifyPaths.
	if (IGameplayAbilitiesModule::IsAvailable())
	{
		IGameplayAbilitiesModule& GameplayAbilitiesModule = IGameplayAbilitiesModule::Get();

		if (GameplayAbilitiesModule.IsAbilitySystemGlobalsAvailable())
		{
			UAbilitySystemGlobals* AbilitySystemGlobals = GameplayAbilitiesModule.GetAbilitySystemGlobals();
			check(AbilitySystemGlobals);

			TArray<FString> GetGameplayCueNotifyPaths = AbilitySystemGlobals->GetGameplayCueNotifyPaths();

			if (GetGameplayCueNotifyPaths.Num() > 0)
			{
				Path = GetGameplayCueNotifyPaths[0];
			}
		}
	}

	GameplayCueTag.RemoveFromStart(TEXT("GameplayCue."));

	FString NewDefaultPathName = FString::Printf(TEXT("%s/GCN_%s"), *Path, *GameplayCueTag);

	return NewDefaultPathName;
#endif
}

static bool HasPlayWorld()
{
	return GEditor->PlayWorld != nullptr;
}

static bool HasNoPlayWorld()
{
	return !HasPlayWorld();
}

static bool HasPlayWorldAndRunning()
{
#if 0
	return HasPlayWorld() && !GUnrealEd->PlayWorld->bDebugPauseExecution;
#endif
}

static void OpenCommonMap_Clicked(const FString MapPath)
{
#if 0
	if (ensure(MapPath.Len()))
	{
		GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(MapPath);
	}
#endif
}

static bool CanShowCommonMaps()
{
#if 0
	return HasNoPlayWorld() && !GetDefault<UGKStarterDeveloperSettings>()->CommonEditorMaps.IsEmpty();
#endif
}

static TSharedRef<SWidget> GetCommonMapsDropdown()
{
#if 0
	FMenuBuilder MenuBuilder(true, nullptr);
	
	for (const FSoftObjectPath& Path : GetDefault<UGKStarterDeveloperSettings>()->CommonEditorMaps)
	{
		if (!Path.IsValid())
		{
			continue;
		}
		
		const FText DisplayName = FText::FromString(Path.GetAssetName());
		MenuBuilder.AddMenuEntry(
			DisplayName,
			LOCTEXT("CommonPathDescription", "Opens this map in the editor"),
			FSlateIcon(),
			FUIAction(
				FExecuteAction::CreateStatic(&OpenCommonMap_Clicked, Path.ToString()),
				FCanExecuteAction::CreateStatic(&HasNoPlayWorld),
				FIsActionChecked(),
				FIsActionButtonVisible::CreateStatic(&HasNoPlayWorld)
			)
		);
	}

	return MenuBuilder.MakeWidget();
#endif
}

static void CheckGameContent_Clicked()
{
#if 0
	UEditorValidator::ValidateCheckedOutContent(/*bInteractive=*/true, EDataValidationUsecase::Manual);
#endif
}

static void RegisterGameEditorMenus()
{
#if 0
	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
	FToolMenuSection& Section = Menu->AddSection("PlayGameExtensions", TAttribute<FText>(), FToolMenuInsert("Play", EToolMenuInsertType::After));

	// Uncomment this to add a custom toolbar that is displayed during PIE
	// Useful for making easy access to changing game state artificially, adding cheats, etc
	// FToolMenuEntry BlueprintEntry = FToolMenuEntry::InitComboButton(
	// 	"OpenGameMenu",
	// 	FUIAction(
	// 		FExecuteAction(),
	// 		FCanExecuteAction::CreateStatic(&HasPlayWorld),
	// 		FIsActionChecked(),
	// 		FIsActionButtonVisible::CreateStatic(&HasPlayWorld)),
	// 	FOnGetContent::CreateStatic(&YourCustomMenu),
	// 	LOCTEXT("GameOptions_Label", "Game Options"),
	// 	LOCTEXT("GameOptions_ToolTip", "Game Options"),
	// 	FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.OpenLevelBlueprint")
	// );
	// BlueprintEntry.StyleNameOverride = "CalloutToolbar";
	// Section.AddEntry(BlueprintEntry);

	FToolMenuEntry CheckContentEntry = FToolMenuEntry::InitToolBarButton(
		"CheckContent",
		FUIAction(
			FExecuteAction::CreateStatic(&CheckGameContent_Clicked),
			FCanExecuteAction::CreateStatic(&HasNoPlayWorld),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateStatic(&HasNoPlayWorld)),
		LOCTEXT("CheckContentButton", "Check Content"),
		LOCTEXT("CheckContentDescription", "Runs the Content Validation job on all checked out assets to look for warnings and errors"),
		FSlateIcon(FGameEditorStyle::GetStyleSetName(), "GameEditor.CheckContent")
	);
	CheckContentEntry.StyleNameOverride = "CalloutToolbar";
	Section.AddEntry(CheckContentEntry);

	FToolMenuEntry CommonMapEntry = FToolMenuEntry::InitComboButton(
		"CommonMapOptions",
		FUIAction(
			FExecuteAction(),
			FCanExecuteAction::CreateStatic(&HasNoPlayWorld),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateStatic(&CanShowCommonMaps)),
		FOnGetContent::CreateStatic(&GetCommonMapsDropdown),
		LOCTEXT("CommonMaps_Label", "Common Maps"),
		LOCTEXT("CommonMaps_ToolTip", "Some commonly desired maps while using the editor"),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Level")
	);
	CommonMapEntry.StyleNameOverride = "CalloutToolbar";
	Section.AddEntry(CommonMapEntry);
#endif
}

/**
 * FGKStarterEditorModule
 */
class FGKStarterEditorModule : public FDefaultGameModuleImpl
{
	typedef FGKStarterEditorModule ThisClass;

	virtual void StartupModule() override
	{
#if 0
		FGameEditorStyle::Initialize();

		if (!IsRunningGame())
		{
			FModuleManager::Get().OnModulesChanged().AddRaw(this, &FGKStarterEditorModule::ModulesChangedCallback);

			BindGameplayAbilitiesEditorDelegates();

			if (FSlateApplication::IsInitialized())
			{
				ToolMenusHandle = UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateStatic(&RegisterGameEditorMenus));
			}

			FEditorDelegates::BeginPIE.AddRaw(this, &ThisClass::OnBeginPIE);
			FEditorDelegates::EndPIE.AddRaw(this, &ThisClass::OnEndPIE);
		}

		// Register the Context Effects Library asset type actions.
		{
			IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
			TSharedRef<FAssetTypeActions_GKStarterContextEffectsLibrary> AssetAction = MakeShared<FAssetTypeActions_GKStarterContextEffectsLibrary>();
			GKStarterContextEffectsLibraryAssetAction = AssetAction;
			AssetTools.RegisterAssetTypeActions(AssetAction);
		}
#endif
	}

	void OnBeginPIE(bool bIsSimulating)
	{
#if 0
		UGKStarterExperienceManager* ExperienceManager = GEngine->GetEngineSubsystem<UGKStarterExperienceManager>();
		check(ExperienceManager);
		ExperienceManager->OnPlayInEditorBegun();
#endif
	}

	void OnEndPIE(bool bIsSimulating)
	{
	}

	virtual void ShutdownModule() override
	{
#if 0
		// Unregister the Context Effects Library asset type actions.
		{
			FAssetToolsModule* AssetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools");
			TSharedPtr<IAssetTypeActions> AssetAction = GKStarterContextEffectsLibraryAssetAction.Pin();
			if (AssetToolsModule && AssetAction)
			{
				AssetToolsModule->Get().UnregisterAssetTypeActions(AssetAction.ToSharedRef());
			}
		}

		FEditorDelegates::BeginPIE.RemoveAll(this);
		FEditorDelegates::EndPIE.RemoveAll(this);

		// Undo UToolMenus
		if (UObjectInitialized() && ToolMenusHandle.IsValid())
		{
			UToolMenus::UnRegisterStartupCallback(ToolMenusHandle);
		}

		UnbindGameplayAbilitiesEditorDelegates();
		FModuleManager::Get().OnModulesChanged().RemoveAll(this);
		FGameEditorStyle::Shutdown();
#endif
	}

protected:

	static void BindGameplayAbilitiesEditorDelegates()
	{
#if 0
		IGameplayAbilitiesEditorModule& GameplayAbilitiesEditorModule = IGameplayAbilitiesEditorModule::Get();

		GameplayAbilitiesEditorModule.GetGameplayCueNotifyClassesDelegate().BindStatic(&GetGameplayCueDefaultClasses);
		GameplayAbilitiesEditorModule.GetGameplayCueInterfaceClassesDelegate().BindStatic(&GetGameplayCueInterfaceClasses);
		GameplayAbilitiesEditorModule.GetGameplayCueNotifyPathDelegate().BindStatic(&GetGameplayCuePath);
#endif
	}

	static void UnbindGameplayAbilitiesEditorDelegates()
	{
#if 0
		if (IGameplayAbilitiesEditorModule::IsAvailable())
		{
			IGameplayAbilitiesEditorModule& GameplayAbilitiesEditorModule = IGameplayAbilitiesEditorModule::Get();
			GameplayAbilitiesEditorModule.GetGameplayCueNotifyClassesDelegate().Unbind();
			GameplayAbilitiesEditorModule.GetGameplayCueInterfaceClassesDelegate().Unbind();
			GameplayAbilitiesEditorModule.GetGameplayCueNotifyPathDelegate().Unbind();
		}
#endif
	}

	void ModulesChangedCallback(FName ModuleThatChanged, EModuleChangeReason ReasonForChange)
	{
#if 0
		if ((ReasonForChange == EModuleChangeReason::ModuleLoaded) && (ModuleThatChanged.ToString() == TEXT("GameplayAbilitiesEditor")))
		{
			BindGameplayAbilitiesEditorDelegates();
		}
#endif
	}

private:
	TWeakPtr<IAssetTypeActions> GKStarterContextEffectsLibraryAssetAction;
	FDelegateHandle ToolMenusHandle;
};

IMPLEMENT_MODULE(FGKStarterEditorModule, GKStarterEditor);

#undef LOCTEXT_NAMESPACE
