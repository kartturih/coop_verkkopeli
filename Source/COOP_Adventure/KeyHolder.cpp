// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyHolder.h"

// Sets default values
AKeyHolder::AKeyHolder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	SetReplicateMovement(true);

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	KeyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMesh"));
	KeyMesh->SetupAttachment(RootComp);
	KeyMesh->SetIsReplicated(true);
	KeyMesh->SetCollisionProfileName(FName("OverlapAllDynamic"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComp);
	Mesh->SetIsReplicated(true);
	Mesh->SetCollisionProfileName(FName("BlockAllDynamic"));

	KeyMeshRotationSpeed = 100.0f;

}

// Called when the game starts or when spawned
void AKeyHolder::BeginPlay()
{
	Super::BeginPlay();
	
	KeyMesh->SetVisibility(false);
}

// Called every frame
void AKeyHolder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	KeyMesh->AddRelativeRotation(FRotator(0.0f, KeyMeshRotationSpeed * DeltaTime, 0.0f));
}

void AKeyHolder::ActivateKeyMesh()
{
	KeyMesh->SetVisibility(true);
}

