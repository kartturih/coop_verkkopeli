// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/AudioComponent.h"
#include "KeyHolder.h"

#include "CollectableKey.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCollectableKeyOnCollected);

UCLASS()
class COOP_ADVENTURE_API ACollectableKey : public AActor
{
	GENERATED_BODY()

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
public:	
	// Sets default values for this actor's properties
	ACollectableKey();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RotationSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AKeyHolder* KeyHolderRef;

	UPROPERTY(ReplicatedUsing = OnRep_IsCollected, BlueprintReadWrite, VisibleAnywhere)
	bool IsCollected;

	UFUNCTION()
	void OnRep_IsCollected();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	USceneComponent* RootComp;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UCapsuleComponent* Capsule;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAudioComponent* CollectAudio;

	FCollectableKeyOnCollected OnCollected;
};
