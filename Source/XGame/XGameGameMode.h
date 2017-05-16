// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "XGameMessages.h"

#include "XGameGameMode.generated.h"

/** GameMode class to specify pawn and playercontroller */
UCLASS(minimalapi)
class AXGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AXGameGameMode();

	//Cailed when the game starts
	virtual void BeginPlay ( ) override;

private:
	//Holds the message EndPoint
	FMessageEndpointPtr MessageEndPoint;

	//Current status fot this mode
	EXGameStatus CurrentGameGameStatus;

	//Handles the game status update messages
	void HandleGameStatusUpdate ( const FMessage_Gameplay_GameStatusUpdate&Message , const IMessageContextRef& Context );
	void OnRoundBegin ( );
	void OnPlayerTurnBegin ( );
	void OnPlayerRegengetate ( );
	void OnPlayerSkillCD ( );
	void OnPlayerBeginInput ( );
	void OnPlayerEndBuildPath ( );
	void OnPlayerEndInput ( );
	void OnEnemyAttack ( );
	void OnRoundEnd ( );
	void OnGameover ( );
};



