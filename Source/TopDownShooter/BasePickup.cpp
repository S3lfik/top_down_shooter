// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownShooter.h"
#include "BasePickup.h"


// Sets default values
ABasePickup::ABasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup mesh"));
	RootComponent = pickupMesh;

	bIsActive = true;
}

// Called when the game starts or when spawned
void ABasePickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool ABasePickup::isActive() const
{
	return bIsActive;;
}

void ABasePickup::setActive(bool active)
{
	bIsActive = active;
}

void ABasePickup::applyPickup_Implementation(ACharacter * targetCharacter)
{
}



