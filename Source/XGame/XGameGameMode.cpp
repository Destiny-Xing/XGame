// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "XGame.h"
#include "XGameGameMode.h"
#include "XGamePlayerController.h"

AXGameGameMode::AXGameGameMode()
{
	// use our own player controller class
	PlayerControllerClass = AXGamePlayerController::StaticClass();

	UE_LOG(LogXGameProcedure, Log, TEXT("Gamemode Construction complete..."));
}
