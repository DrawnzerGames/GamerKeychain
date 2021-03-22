// Copyright 2021 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Model/KeychainReadModel.h"
#include "Model/KeychainSaveModel.h"
#include "KeychainPlatformContract.generated.h"

UCLASS()
class UKeychainPlatformContract : public UObject
{
	GENERATED_BODY()

public:
	virtual FString ReadFromKeychain(FKeychainReadModel KeychainReadModel) { return ""; }
	virtual bool DeleteFromKeychain(FKeychainReadModel KeychainReadModel) { return false; }
	virtual bool SaveInKeychain(FKeychainSaveModel KeychainSaveModel) { return false; }
};
