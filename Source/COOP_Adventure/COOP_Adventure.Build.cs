// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class COOP_Adventure : ModuleRules
{
	public COOP_Adventure(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "OnlineSubsystem", "OnlineSubsystemSteam" });
	}
}
