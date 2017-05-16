#pragma once

#include "XGameMessages.generated.h"

UENUM()
enum class EXGameStatus : uint8
{
	EGS_Init ,
	EGS_GameStart,
	EGS_RoundBegin,
	EGS_PlayerTurnBegin,
	EGS_PlayerRegengetate,
	EGS_PlayerSkillCD,
	EGS_PlayerBeginInput,
	EGS_PlayerEndBuildPath,
	EGS_PlayerEndInput,
	EGS_EnemyAttack,
	EGS_RoundEnd,
	EGS_Gameover,
};

USTRUCT()
struct FMessage_Gameplay_GameStatusUpdate
{
		GENERATED_USTRUCT_BODY()

		//The new game status
		UPROPERTY()
		EXGameStatus NewGameStatus;
};
