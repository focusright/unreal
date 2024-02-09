#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ImGuiActor.generated.h"

UCLASS()
class IMGUITEST_API AImGuiActor : public AActor {
	GENERATED_BODY()
	
public:	
	AImGuiActor();

protected:
	virtual void BeginPlay() override;
	float scale { 1.0f };
	float scaleOld { scale };

public:	
	virtual void Tick(float DeltaTime) override;
};
