#include "COOP_AdventureCharacter.h"
#include "WinArea.h"

AWinArea::AWinArea()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	WinAreaBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WinAreaBox"));
	SetRootComponent(WinAreaBox);

	WinCondition = false;

}

void AWinArea::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWinArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		if (!WinCondition)
		{
			TArray<AActor*> OverlapActors;
			WinAreaBox->GetOverlappingActors(OverlapActors, ACOOP_AdventureCharacter::StaticClass());

			WinCondition = (OverlapActors.Num() == 2);
			if (WinCondition)
			{
				UE_LOG(LogTemp, Display, TEXT("Win!"));

				MulticastRPCWin();
			}
		}
	}


}

void AWinArea::MulticastRPCWin_Implementation()
{
	OnWinCondition.Broadcast();
}