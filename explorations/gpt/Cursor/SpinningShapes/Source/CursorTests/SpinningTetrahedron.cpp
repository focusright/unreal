// Fill out your copyright notice in the Description page of Project Settings.

#include "SpinningTetrahedron.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ASpinningTetrahedron::ASpinningTetrahedron()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and setup the mesh component
	TetrahedronMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TetrahedronMesh"));
	RootComponent = TetrahedronMesh;

	// Try to load the cone static mesh as our tetrahedron
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cone"));
	if (MeshAsset.Succeeded())
	{
		TetrahedronMesh->SetStaticMesh(MeshAsset.Object);
		TetrahedronMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}
}

// Called when the game starts or when spawned
void ASpinningTetrahedron::BeginPlay()
{
	Super::BeginPlay();

	// Load and create the patterned material
	UMaterial* BaseMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("/Game/Materials/M_ColoredPattern")));
	if (BaseMaterial)
	{
		UMaterialInstanceDynamic* PatternedMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, this);
		if (PatternedMaterial)
		{
			PatternedMaterial->SetScalarParameterValue(TEXT("PatternTiling"), 20.0f);
			PatternedMaterial->SetVectorParameterValue(TEXT("PrimaryColor"), PrimaryBlue);
			PatternedMaterial->SetVectorParameterValue(TEXT("SecondaryColor"), SecondaryBlue);
			TetrahedronMesh->SetMaterial(0, PatternedMaterial);
		}
	}
}

// Called every frame
void ASpinningTetrahedron::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Calculate rotation for this frame
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += RotationSpeed * DeltaTime;
	
	// Set the new rotation
	SetActorRotation(NewRotation);
}

