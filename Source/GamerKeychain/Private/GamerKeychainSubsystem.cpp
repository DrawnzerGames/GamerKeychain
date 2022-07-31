//  Copyright 2022 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#include "GamerKeychainSubsystem.h"
#include "Manager/GamerKeychainManager.h"

UGamerKeychainSubsystem* UGamerKeychainSubsystem::Subsystem;

UGamerKeychainSubsystem* UGamerKeychainSubsystem::Get()
{
	return Subsystem;
}

bool UGamerKeychainSubsystem::SaveInKeychainSync(const FKeychainSaveModel& KeychainValue)
{
	return UGamerKeychainManager::Get()->SaveInKeychain(KeychainValue);
}

FString UGamerKeychainSubsystem::ReadFromKeychainSync(const FKeychainReadModel& KeychainValue)
{
	return UGamerKeychainManager::Get()->ReadFromKeychain(KeychainValue);
}

bool UGamerKeychainSubsystem::DeleteFromKeychainSync(const FKeychainReadModel& KeychainValue)
{
	return UGamerKeychainManager::Get()->DeleteFromKeychain(KeychainValue);
}

void UGamerKeychainSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UGamerKeychainManager::Create();
	Subsystem = GEngine->GetEngineSubsystem<UGamerKeychainSubsystem>();
}
