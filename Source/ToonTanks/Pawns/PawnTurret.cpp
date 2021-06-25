// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "ToonTanks/Pawns/PawnTank.h"

APawnTurret::APawnTurret(){

}

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange){
        return;
    }

    RotateTurretFunction(PlayerPawn->GetActorLocation());
}


void APawnTurret::CheckFireCondition(){
    if(!PlayerPawn){
        return;
    }
    if(ReturnDistanceToPlayer() <= this->FireRange){
        Fire();
    }
}

float APawnTurret::ReturnDistanceToPlayer(){
    if(!PlayerPawn){
        return 0.0f;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(), this->GetActorLocation());
    
}

void APawnTurret::HandleDestruction(){
    Super::HandleDestruction();
    Destroy();
}