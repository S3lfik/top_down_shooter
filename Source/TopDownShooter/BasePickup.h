// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BasePickup.generated.h"

UCLASS()
class TOPDOWNSHOOTER_API ABasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FORCEINLINE class UStaticMeshComponent* getMesh() const { return pickupMesh; }

	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool isActive() const;

	UFUNCTION(BlueprintCallable, Category = "Pickup") 
	void setActive(bool active);

protected:
	bool bIsActive;

protected:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Pickup")
	virtual void applyPickup(ACharacter* targetCharacter);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* pickupMesh;
	
	
};
