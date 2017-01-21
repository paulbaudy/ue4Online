// Fill out your copyright notice in the Description page of Project Settings.

#include "AmbulanceReseau.h"
#include "MyPlayerController.h"

#include "Runtime/UMG/Public/UMG.h"

AMyPlayerController::AMyPlayerController() : APlayerController() {

}

void AMyPlayerController::BeginPlay() {
	Super::BeginPlay();
	
	FStringClassReference MyWidgetClassRef(TEXT("/Game/Maps/MainMenuWidget.MainMenuWidget_C"));

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg");
	
	if (UClass* MyWidgetClass = MyWidgetClassRef.TryLoadClass<UUserWidget>())
	{
		UUserWidget* MyWidget = CreateWidget<UUserWidget>(GetWorld(), MyWidgetClass);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg");
		MyWidget->AddToViewport();
		bShowMouseCursor = true;

	}


}