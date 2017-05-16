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

void AXGameGameMode::BeginPlay ( )
{
	Super::BeginPlay ( );

	//Create messaging end point for game mode
	MessageEndPoint = FMessageEndpoint::Builder ( "Gameplay_GameMode" )
		.Handling<FMessage_Gameplay_GameStatusUpdate> ( this , &AXGameGameMode::HandleGameStatusUpdate );
	
	check ( MessageEndPoint.IsValid ( ) );
	MessageEndPoint->Subscribe<FMessage_Gameplay_GameStatusUpdate> ( );
}

void AXGameGameMode::HandleGameStatusUpdate ( const FMessage_Gameplay_GameStatusUpdate & Message , const IMessageContextRef & Context )
{
	CurrentGameGameStatus = Message.NewGameStatus;

	switch ( CurrentGameGameStatus )
	{
	case EXGameStatus::EGS_RoundBegin:
		OnRoundBegin ( );
		break;
	case EXGameStatus::EGS_PlayerTurnBegin:
		OnPlayerTurnBegin ( );
		break;
	case EXGameStatus::EGS_PlayerRegengetate:
		OnPlayerRegengetate ( );
		break;
	case EXGameStatus::EGS_PlayerSkillCD:
		OnPlayerSkillCD ( );
		break;
	case EXGameStatus::EGS_PlayerBeginInput:
		OnPlayerBeginInput ( );
		break;
	case EXGameStatus::EGS_PlayerEndBuildPath:
		OnPlayerEndBuildPath ( );
		break;
	case EXGameStatus::EGS_PlayerEndInput:
		OnPlayerEndInput ( );
		break;
	case EXGameStatus::EGS_EnemyAttack:
		OnEnemyAttack ( );
		break;
	case EXGameStatus::EGS_RoundEnd:
		OnRoundEnd ( );
		break;
	case EXGameStatus::EGS_Gameover:
		OnGameover ( );
		break;
	default:
		UE_LOG ( LogXGameProcedure , Log , TEXT ( "Error" ) );
		break;
	}
}

void AXGameGameMode::OnRoundBegin ( )
{
	UE_LOG ( LogXGameProcedure , Log , TEXT ( "OnRoundBegin" ) );

	check ( MessageEndPoint.IsValid ( ) );
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate ( );
	Message->NewGameStatus = EXGameStatus::EGS_PlayerTurnBegin;
	MessageEndPoint->Publish ( Message , EMessageScope::Process );
}

void AXGameGameMode::OnPlayerTurnBegin ( )
{
	UE_LOG ( LogXGameProcedure , Log , TEXT ( "OnPlayerTurnBegin" ) );

	check ( MessageEndPoint.IsValid ( ) );
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate ( );
	Message->NewGameStatus = EXGameStatus::EGS_PlayerRegengetate;
	MessageEndPoint->Publish ( Message , EMessageScope::Process );
}

void AXGameGameMode::OnPlayerRegengetate ( )
{
	UE_LOG ( LogXGameProcedure , Log , TEXT ( "OnPlayerRegengetate" ) );

	check ( MessageEndPoint.IsValid ( ) );
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate ( );
	Message->NewGameStatus = EXGameStatus::EGS_PlayerSkillCD;
	MessageEndPoint->Publish ( Message , EMessageScope::Process );
}

void AXGameGameMode::OnPlayerSkillCD ( )
{
	UE_LOG ( LogXGameProcedure , Log , TEXT ( "OnPlayerSkillCD" ) );

	check ( MessageEndPoint.IsValid ( ) );
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate ( );
	Message->NewGameStatus = EXGameStatus::EGS_PlayerBeginInput;
	MessageEndPoint->Publish ( Message , EMessageScope::Process );
}

void AXGameGameMode::OnPlayerBeginInput ( )
{
	UE_LOG ( LogXGameProcedure , Log , TEXT ( "OnPlayerBeginInput" ) );

	check ( MessageEndPoint.IsValid ( ) );
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate ( );
	Message->NewGameStatus = EXGameStatus::EGS_PlayerEndBuildPath;
	MessageEndPoint->Publish ( Message , EMessageScope::Process );
}

void AXGameGameMode::OnPlayerEndBuildPath ( )
{
	UE_LOG ( LogXGameProcedure , Log , TEXT ( "OnPlayerEndBuildPath" ) );

	check ( MessageEndPoint.IsValid ( ) );
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate ( );
	Message->NewGameStatus = EXGameStatus::EGS_PlayerEndInput;
	MessageEndPoint->Publish ( Message , EMessageScope::Process );
}

void AXGameGameMode::OnPlayerEndInput ( )
{
	UE_LOG ( LogXGameProcedure , Log , TEXT ( "OnPlayerEndInput" ) );

	check ( MessageEndPoint.IsValid ( ) );
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate ( );
	Message->NewGameStatus = EXGameStatus::EGS_EnemyAttack;
	MessageEndPoint->Publish ( Message , EMessageScope::Process );
}

void AXGameGameMode::OnEnemyAttack ( )
{
	UE_LOG ( LogXGameProcedure , Log , TEXT ( "OnEnemyAttack" ) );

	check ( MessageEndPoint.IsValid ( ) );
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate ( );
	Message->NewGameStatus = EXGameStatus::EGS_RoundEnd;
	MessageEndPoint->Publish ( Message , EMessageScope::Process );
}

void AXGameGameMode::OnRoundEnd ( )
{
	UE_LOG ( LogXGameProcedure , Log , TEXT ( "OnRoundEnd" ) );

#if(0)
	check ( MessageEndPoint.IsValid ( ) );
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate ( );
	Message->NewGameStatus = EXGameStatus::EGS_RoundBegin;
	MessageEndPoint->Publish ( Message , EMessageScope::Process );
#endif
}

void AXGameGameMode::OnGameover ( )
{
	UE_LOG ( LogXGameProcedure , Log , TEXT ( "OnEGS_Gameover" ) );
}
