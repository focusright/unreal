// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinningCylinder.generated.h"

UCLASS()
class CURSORTESTS_API ASpinningCylinder : public AActor
{
    GENERATED_BODY()
    
public:    
    // Sets default values for this actor's properties
    ASpinningCylinder();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, Category = "Material")
    FLinearColor PrimaryRed = FLinearColor(1.0f, 0.0f, 0.0f, 1.0f);

    UPROPERTY(EditAnywhere, Category = "Material")
    FLinearColor SecondaryRed = FLinearColor(0.5f, 0.0f, 0.0f, 1.0f);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Static mesh component for the cylinder
    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* CylinderMesh;

    // Rotation speed (degrees per second)
    UPROPERTY(EditAnywhere, Category = "Movement")
    float RotationSpeed = 90.0f;
}; 