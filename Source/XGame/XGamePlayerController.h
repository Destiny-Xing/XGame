// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "XGamePlayerController.generated.h"

/** PlayerController class used to enable cursor */
UCLASS()
class AXGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AXGamePlayerController();

private:
	//Holds the message EndPoint
	FMessageEndpointPtr MessageEndPoint;
};


