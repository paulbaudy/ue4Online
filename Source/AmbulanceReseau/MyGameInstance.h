// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"




UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EStateEnum : uint8
{
	VE_Startup 	UMETA(DisplayName = "Startup"),
	VE_Playing	UMETA(DisplayName = "Playing")
};

/**
 * 
 */
UCLASS()
class AMBULANCERESEAU_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMyGameInstance();


	UFUNCTION(BlueprintCallable, Category = "Begin")
	void BeginPlayShowMainMenu();

	UFUNCTION(BlueprintCallable, Category = "Begin")
	void ShowMainMenu();

	UFUNCTION(BlueprintCallable, Category = "Network")
		/**
		*	Function to host a game!
		*
		*	@Param		UserID			User that started the request
		*	@Param		SessionName		Name of the Session
		*	@Param		bIsLAN			Is this is LAN Game?
		*	@Param		bIsPresence		"Is the Session to create a presence Session"
		*	@Param		MaxNumPlayers	        Number of Maximum allowed players on this "Session" (Server)
		*/
	bool HostSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers);

	/* Delegate called when session created */
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	/* Delegate called when session started */
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;

	/** Handles to registered delegates for creating/starting a session */
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FDelegateHandle OnStartSessionCompleteDelegateHandle;


	UFUNCTION(BlueprintCallable, Category = "Macros")
	bool isCurrentState(EStateEnum state);

	UFUNCTION(BlueprintCallable, Category = "Macros")
	bool TransitionToState(EStateEnum toState);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EStateEnum CurrentState;
	
};
