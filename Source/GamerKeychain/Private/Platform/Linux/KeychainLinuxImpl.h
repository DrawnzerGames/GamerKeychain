// Copyright 2021 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "KeychainPlatformContract.h"
#include "KeychainLinuxImpl.generated.h"

/**
 * 
 */
UCLASS()
class UKeychainLinuxImpl : public UKeychainPlatformContract
{
	GENERATED_BODY()
	
protected:
	virtual FString ReadFromKeychain(FKeychainReadModel KeychainReadModel) override;
	virtual bool DeleteFromKeychain(FKeychainReadModel KeychainReadModel) override;
	virtual bool SaveInKeychain(FKeychainSaveModel KeychainSaveModel) override;
};
