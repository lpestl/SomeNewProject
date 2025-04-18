// Fill out your copyright notice in the Description page of Project Settings.


#include "SomeNewGameMode.h"

#include "RESTApiServer.h"
#include "SupabaseClient.h"

void ASomeNewGameMode::BeginPlay()
{
	Super::BeginPlay();

	RestApiServer = NewObject<URESTApiServer>();
	RestApiServer->OnReceivedRequest().AddDynamic(this, &ASomeNewGameMode::OnReceivedRequest);
	RestApiServer->StartApiServer();

	// Create client
	SupabaseClient = NewObject<USupabaseClient>();
	// Subscribe to the events you need
	SupabaseClient->OnSupabaseConnected().AddDynamic(this, &ASomeNewGameMode::OnSupabaseConnected);
	SupabaseClient->OnSupabaseReady().AddDynamic(this, &ASomeNewGameMode::OnSupabaseReady);
	SupabaseClient->OnSupabaseResponseComplete().AddDynamic(this, &ASomeNewGameMode::OnSupabaseResponseComplete);
	// Connect to DB
	SupabaseClient->Connect();
}

void ASomeNewGameMode::OnSupabaseConnected()
{
}

void ASomeNewGameMode::OnSupabaseReady()
{
}

void ASomeNewGameMode::OnSupabaseResponseComplete(const FSupabaseResponse& Response)
{
}

void ASomeNewGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	SupabaseClient->Disconnect();
	RestApiServer->StopApiServer();
	
	Super::EndPlay(EndPlayReason);
}

void ASomeNewGameMode::OnReceivedRequest(const FString& RequestBody, FEndpointData EndpointData)
{
	//...
}


