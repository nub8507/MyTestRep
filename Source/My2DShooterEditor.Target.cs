// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class My2DShooterEditorTarget : TargetRules
{
	public My2DShooterEditorTarget(TargetInfo Target): base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("My2DShooter");
	}

}
