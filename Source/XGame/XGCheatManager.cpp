// Fill out your copyright notice in the Description page of Project Settings.

#include "XGame.h"
#include "XGameMessages.h"
#include "XGCheatManager.h"

UXGCheatManager::UXGCheatManager ( )
{
	MessageEndPoint = FMessageEndpoint::Builder ( "UXGCheatManagerEndpoint" );
}

void UXGCheatManager::StartGame()
{
	UE_LOG(LogXGameProcedure, Log, TEXT("Force start game"));

	check ( MessageEndPoint.IsValid ( ) );
	
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate ( );
	Message->NewGameStatus = EXGameStatus::EGS_RoundBegin;
	MessageEndPoint->Publish ( Message , EMessageScope::Process );

}
