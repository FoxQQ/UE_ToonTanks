// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ToonTanks/Pawns/BasePawn.h"
#include "PawnTurret.generated.h"

/**
 * 
 */
class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public ABasePawn
{
	GENERATED_BODY()
	
private:
	APawnTank* PlayerPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat",   meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat",   meta = (AllowPrivateAccess = "true"))
	float FireRange = 500.f;

	FTimerHandle FireRateTimerHandle;

	float ReturnDistanceToPlayer();
	void CheckFireCondition();

public:
APawnTurret();
virtual void Tick(float DeltaTime) override;

protected:
virtual void BeginPlay() override;
virtual void HandleDestruction() override;

};
