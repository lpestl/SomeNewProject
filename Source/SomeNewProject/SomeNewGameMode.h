// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SupabaseResponse.h"
#include "Config/RESTApiServerSettings.h"
#include "GameFramework/GameMode.h"
#include "SomeNewGameMode.generated.h"

class USupabaseClient;
class URESTApiServer;
/**
 * 
 */
UCLASS()
class SOMENEWPROJECT_API ASomeNewGameMode : public AGameMode
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void OnReceivedRequest(const FString& RequestBody, FEndpointData EndpointData);

	UFUNCTION()
	void OnSupabaseConnected();
	UFUNCTION()
	void OnSupabaseReady();	
	UFUNCTION()
	void OnSupabaseResponseComplete(const FSupabaseResponse& Response);
	
private:
	UPROPERTY(EditAnywhere)
	URESTApiServer* RestApiServer;

	UPROPERTY(EditAnywhere)
	USupabaseClient* SupabaseClient;
};
