#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinningCube.generated.h"

UCLASS()
class CURSORTESTS_API ASpinningCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpinningCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CubeMesh;

	UPROPERTY(EditAnywhere, Category = "Spinning")
	float RotationRate = 90.0f; // Degrees per second

	UPROPERTY(EditAnywhere, Category = "Material")
	FLinearColor PrimaryGreen = FLinearColor(0.0f, 1.0f, 0.0f, 1.0f);

	UPROPERTY(EditAnywhere, Category = "Material")
	FLinearColor SecondaryGreen = FLinearColor(0.0f, 0.5f, 0.0f, 1.0f);
};
