// Copyright 2021 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#include "Proxy/GamerKeychainProxy.h"
#include "Manager/GamerKeychainManager.h"

USaveGamerKeychainProxy* USaveGamerKeychainProxy::SaveInKeychain(const FKeychainSaveModel KeychainValue)
{
	USaveGamerKeychainProxy* SaveGamerKeychainProxy = NewObject<USaveGamerKeychainProxy>(GetTransientPackage());
	SaveGamerKeychainProxy->KeychainSaveModel = KeychainValue;
	return SaveGamerKeychainProxy;
}

void USaveGamerKeychainProxy::Activate()
{
	UGamerKeychainManager::Create();
	const auto Result = UGamerKeychainManager::Get()->SaveInKeychain(KeychainSaveModel);
	OnSaved.Broadcast(Result);
}

UReadGamerKeychainProxy* UReadGamerKeychainProxy::ReadFromKeychain(const FKeychainReadModel KeychainValue)
{
	UReadGamerKeychainProxy* ReadGamerKeychain = NewObject<UReadGamerKeychainProxy>(GetTransientPackage());
	ReadGamerKeychain->KeychainReadModel = KeychainValue;
	return ReadGamerKeychain;
}

void UReadGamerKeychainProxy::Activate()
{
	UGamerKeychainManager::Create();
	const auto Result = UGamerKeychainManager::Get()->ReadFromKeychain(KeychainReadModel);
	OnRead.Broadcast(Result.Len() > 0, Result);
}

UDeleteGamerKeychainProxy* UDeleteGamerKeychainProxy::DeleteFromKeychain(const FKeychainReadModel KeychainValue)
{
	UDeleteGamerKeychainProxy* ReadGamerKeychain = NewObject<UDeleteGamerKeychainProxy>(GetTransientPackage());
	ReadGamerKeychain->KeychainReadModel = KeychainValue;
	return ReadGamerKeychain;
}

void UDeleteGamerKeychainProxy::Activate()
{
	UGamerKeychainManager::Create();
	const auto Result = UGamerKeychainManager::Get()->DeleteFromKeychain(KeychainReadModel);
	OnDelete.Broadcast(Result);
}
