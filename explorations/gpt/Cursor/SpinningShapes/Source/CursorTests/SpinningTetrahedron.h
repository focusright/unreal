// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinningTetrahedron.generated.h"

UCLASS()
class CURSORTESTS_API ASpinningTetrahedron : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpinningTetrahedron();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Static mesh component for the tetrahedron
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* TetrahedronMesh;

	// Rotation speed (degrees per second)
	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationSpeed = 90.0f;

	UPROPERTY(EditAnywhere, Category = "Material")
	FLinearColor PrimaryBlue = FLinearColor(0.0f, 0.0f, 1.0f, 1.0f);

	UPROPERTY(EditAnywhere, Category = "Material")
	FLinearColor SecondaryBlue = FLinearColor(0.0f, 0.0f, 0.5f, 1.0f);
};
