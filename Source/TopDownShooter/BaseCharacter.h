// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class TOPDOWNSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	UENUM(Blueprintable)
	enum class AllianceType : uint8
	{
		Neutral		UMETA(DisplayName = "Neutral"),
		Ally		UMETA(DisplayName = "Ally"),
		Enemy		UMETA(DisplayName = "Enemy"),
	};
	//Step 2: Expose a float property



	//Step 4: Make a helper function, just because we are lazy
	virtual void CalculateDead();

	//Step 5: Expose a method
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	virtual void CalculateHealth(float delta);


	//Step 6: Editor code to make updating values in the editor cleaner
#if WITH_EDITOR
		virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "BaseCharacter")
		float _damage;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "BaseCharacter")
		float _attackSpeed;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "BaseCharacter")
		float _health;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "BaseCharacter")
		float _baseHealth;

	//Step 3: Expose a boolean property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "BaseCharacter")
		bool _isDead;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "BaseCharacter")
	AllianceType _allianceType;

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "BaseCharacter")
	virtual void attack();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "BaseCharacter")
	virtual void stopAttack();
};
