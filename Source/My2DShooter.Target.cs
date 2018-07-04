// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class My2DShooterTarget : TargetRules
{
	public My2DShooterTarget(TargetInfo Target): base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("My2DShooter");
	}

}
