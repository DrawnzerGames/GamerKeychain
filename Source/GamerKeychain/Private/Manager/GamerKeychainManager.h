// Copyright 2021 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "KeychainPlatformContract.h"
#include "Model/KeychainSaveModel.h"
#include "GamerKeychainManager.generated.h"

/**
 * 
 */
UCLASS()
class UGamerKeychainManager : public UObject
{
	GENERATED_BODY()

public:
	static void Create();
	static UGamerKeychainManager* Get();
	bool SaveInKeychain(FKeychainSaveModel KeychainSaveModel) const;
	FString ReadFromKeychain(FKeychainReadModel KeychainReadModel) const;
	bool DeleteFromKeychain(FKeychainReadModel KeychainReadModel) const;

private:
	UGamerKeychainManager();
	static UGamerKeychainManager* GamerKeychainManager;

	UPROPERTY()
	UKeychainPlatformContract* PlatformKeychainService;
};
