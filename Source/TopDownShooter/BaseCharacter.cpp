// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownShooter.h"
#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_health = 100.f;
	_isDead = false;
	_allianceType = AllianceType::Neutral;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}
//Step 1: Implement the CalculateHealth function.
void ABaseCharacter::CalculateHealth(float Delta)
{
	_health += Delta;
	CalculateDead();
}

//Step 2: Implement the CalculateDead function.
void ABaseCharacter::CalculateDead()
{
	if (_health <= 0)
	{
		_isDead = true;
		_health = 0;
	}
	else
		_isDead = false;

}
#if WITH_EDITOR
//Step 3: Implement the remainder of our helper code, used by the editor when we change values.
void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	_isDead = false;
	_health = 100;
	_allianceType = AllianceType::Neutral;
	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDead();
}
#endif



