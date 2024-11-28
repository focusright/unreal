// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "STPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STATETREE_API ASTPlayerController : public APlayerController, public IGenericTeamAgentInterface {
	GENERATED_BODY()

public:
    ASTPlayerController(const FObjectInitializer& ObjectInitializer);

	//----------------------------------------------------------------------//
	// IGenericTeamAgentInterface
	//----------------------------------------------------------------------//
public:
	virtual void SetGenericTeamId(const FGenericTeamId& NewTeamId) override;
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }

private:
	FGenericTeamId TeamId;
};
