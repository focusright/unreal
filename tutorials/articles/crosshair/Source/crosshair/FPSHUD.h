// https://docs.unrealengine.com/en-US/Programming/Tutorials/FirstPersonShooter/3/5/index.html

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSHUD.generated.h"

/**
 *
 */
UCLASS()
class CROSSHAIR_API AFPSHUD : public AHUD {
    GENERATED_BODY()
public:
    // Primary draw call for the HUD.
    virtual void DrawHUD() override;
protected:
    // This will be drawn at the center of the screen.
    UPROPERTY(EditDefaultsOnly)
        UTexture2D* CrosshairTexture;
};
