// Fill out your copyright notice in the Description page of Project Settings.

#include "SpinningCylinder.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ASpinningCylinder::ASpinningCylinder()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;

    // Create and setup the mesh component
    CylinderMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CylinderMesh"));
    RootComponent = CylinderMesh;

    // Try to load the cylinder static mesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cylinder"));
    if (MeshAsset.Succeeded())
    {
        CylinderMesh->SetStaticMesh(MeshAsset.Object);
        CylinderMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
    }
}

// Called when the game starts or when spawned
void ASpinningCylinder::BeginPlay()
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
            PatternedMaterial->SetVectorParameterValue(TEXT("PrimaryColor"), PrimaryRed);
            PatternedMaterial->SetVectorParameterValue(TEXT("SecondaryColor"), SecondaryRed);
            CylinderMesh->SetMaterial(0, PatternedMaterial);
        }
    }
}

// Called every frame
void ASpinningCylinder::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Calculate rotation for this frame
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += RotationSpeed * DeltaTime;
    
    // Set the new rotation
    SetActorRotation(NewRotation);
} 