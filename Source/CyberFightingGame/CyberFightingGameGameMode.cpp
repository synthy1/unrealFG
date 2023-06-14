// Copyright Epic Games, Inc. All Rights Reserved.

#include "CyberFightingGameGameMode.h"
#include "CyberFightingGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACyberFightingGameGameMode::ACyberFightingGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
