// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanks/Pawns/BasePawn.h"
#include "Components/CapsuleComponent.h"
// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);
	
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

}


void ABasePawn::RotateTurretFunction(FVector LookAtTarget){

	FVector LookAtTargetClean = FVector(LookAtTarget.X,
										LookAtTarget.Y,
										TurretMesh->GetComponentLocation().Z);

	FVector StartLocation = TurretMesh->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTargetClean - StartLocation).Rotation();
	TurretMesh->SetWorldRotation(TurretRotation);
}

void ABasePawn::Fire(){
	UE_LOG(LogTemp, Error, TEXT("FIRE!"));

}

void ABasePawn::HandleDestruction(){

}
