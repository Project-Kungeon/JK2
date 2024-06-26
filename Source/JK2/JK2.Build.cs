// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JK2 : ModuleRules
{
	public JK2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		//Add EnhancedInput
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] { "ThirdParty" });

        PrivateIncludePaths.AddRange(new string[]
        {
            "JK2/",
            "JK2/Network/",
            "JK2/Network/PacketHandler",
            "JK2/System/"
        });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
