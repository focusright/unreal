// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintFilter.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"
//#include "ShaderCore.h"

void FPaintFilter::StartupModule() {
    FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders"));
    AddShaderSourceDirectoryMapping("/Project", ShaderDirectory);
}

IMPLEMENT_PRIMARY_GAME_MODULE(FPaintFilter, PaintFilter, "PaintFilter" );
