// Fill out your copyright notice in the Description page of Project Settings.


#include "STCharacter.h"

// Sets default values
ASTCharacter::ASTCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASTCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASTCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASTCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}








void ASTCharacter::SetGenericTeamId(const FGenericTeamId& NewTeamId) {
	if (TeamId != NewTeamId) {
		TeamId = NewTeamId;
	}
}

void ASTCharacter::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);

	if (IGenericTeamAgentInterface* ControllerAsTeamProvider = Cast<IGenericTeamAgentInterface>(NewController)) {
		TeamId = ControllerAsTeamProvider->GetGenericTeamId();
	}
}

