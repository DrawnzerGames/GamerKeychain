// Copyright 2021 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#include "Manager/GamerKeychainManager.h"
#if PLATFORM_WINDOWS
#include "Platform/Windows/KeychainWindowsImpl.h"
#endif

UGamerKeychainManager* UGamerKeychainManager::GamerKeychainManager;

void UGamerKeychainManager::Create()
{
	if (GamerKeychainManager != nullptr)
	{
		return;
	}
	GamerKeychainManager = NewObject<UGamerKeychainManager>(GetTransientPackage(), TEXT("GamerKeychainManager"));
	GamerKeychainManager->AddToRoot();

#if PLATFORM_WINDOWS
	Get()->PlatformKeychainService = NewObject<UKeychainWindowsImpl>(GetTransientPackage(), TEXT("Windows_PlatformKeychainService"));
#endif
}

UGamerKeychainManager* UGamerKeychainManager::Get()
{
	return GamerKeychainManager;
}

bool UGamerKeychainManager::SaveInKeychain(FKeychainSaveModel KeychainSaveModel) const
{
	return PlatformKeychainService->SaveInKeychain(KeychainSaveModel);
}

FString UGamerKeychainManager::ReadFromKeychain(FKeychainReadModel KeychainReadModel) const
{
	return PlatformKeychainService->ReadFromKeychain(KeychainReadModel);
}

bool UGamerKeychainManager::DeleteFromKeychain(FKeychainReadModel KeychainReadModel) const
{
	return PlatformKeychainService->DeleteFromKeychain(KeychainReadModel);
}

UGamerKeychainManager::UGamerKeychainManager()
{
}
