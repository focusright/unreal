// Fill out your copyright notice in the Description page of Project Settings.
#include "STPlayerController.h"

ASTPlayerController::ASTPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	SetGenericTeamId(FGenericTeamId(2));
}

void ASTPlayerController::SetGenericTeamId(const FGenericTeamId& NewTeamId) {
	if (TeamId != NewTeamId) {
		TeamId = NewTeamId;
	}
}

