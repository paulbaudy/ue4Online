// Fill out your copyright notice in the Description page of Project Settings.

#include "AmbulanceReseau.h"
#include "MyGameInstance.h"


UMyGameInstance::UMyGameInstance() : UGameInstance() {

	
	CurrentState = EStateEnum::VE_Startup;
}

void UMyGameInstance::BeginPlayShowMainMenu() {
	if (isCurrentState(EStateEnum::VE_Startup)) {
		ShowMainMenu();
	}
}

bool UMyGameInstance::HostSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers) {

}

void UMyGameInstance::ShowMainMenu() {
	if (isCurrentState(EStateEnum::VE_Playing)) {
		UGameplayStatics::OpenLevel(this, TEXT("World'/Game/Maps/MainMenu.MainMenu"));
	}

	//UserInterface = CreateWidget<UMyUserWidget>(this, UMyUserWidget::StaticClass());
	APlayerController* _PlayerController = GetWorld()->GetFirstPlayerController();
}

bool UMyGameInstance::isCurrentState(EStateEnum state) {
	if (state == CurrentState) return true;
	return false;
}

bool UMyGameInstance::TransitionToState(EStateEnum toState) {
	CurrentState = toState;
	return true;
}