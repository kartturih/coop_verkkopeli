// Copyright Epic Games, Inc. All Rights Reserved.

#include "COOP_AdventureGameMode.h"
#include "COOP_AdventureCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACOOP_AdventureGameMode::ACOOP_AdventureGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
