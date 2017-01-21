// Fill out your copyright notice in the Description page of Project Settings.

#include "AmbulanceReseau.h"
#include "MyGameMode.h"

#include "MyPlayerController.h"


AMyGameMode::AMyGameMode() : AGameMode() {
	PlayerControllerClass = AMyPlayerController::StaticClass();
}