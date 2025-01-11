#include "SpinningCube.h"

ASpinningCube::ASpinningCube()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create and setup the cube mesh
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    RootComponent = CubeMesh;

    // Load the cube static mesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube"));
    if (CubeMeshAsset.Succeeded())
    {
        CubeMesh->SetStaticMesh(CubeMeshAsset.Object);
    }
}

void ASpinningCube::BeginPlay()
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
            PatternedMaterial->SetVectorParameterValue(TEXT("PrimaryColor"), PrimaryGreen);
            PatternedMaterial->SetVectorParameterValue(TEXT("SecondaryColor"), SecondaryGreen);
            CubeMesh->SetMaterial(0, PatternedMaterial);
        }
    }
}

void ASpinningCube::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Calculate rotation this frame
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += RotationRate * DeltaTime;

    // Set the new rotation
    SetActorRotation(NewRotation);
}