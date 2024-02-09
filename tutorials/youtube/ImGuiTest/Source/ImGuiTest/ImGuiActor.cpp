#include "ImGuiActor.h"
#include <ImGui.h>

AImGuiActor::AImGuiActor() {
	PrimaryActorTick.bCanEverTick = true;
}
void AImGuiActor::BeginPlay() {
	Super::BeginPlay();
}
void AImGuiActor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	//ImGui::ShowDemoWindow();

	const FString Label = GetActorLabel();

	ImGui::Begin(TCHAR_TO_ANSI(*Label), nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::SliderFloat("Scale", & scale, 0.1f, 5.0f);
	ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
	ImGui::End();

	if (scale != scaleOld) {
		scaleOld = scale;
		SetActorScale3D(FVector3d(scale));
	}
}

