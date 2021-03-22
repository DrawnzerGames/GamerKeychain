// Copyright 2021 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "KeychainSaveModel.generated.h"

USTRUCT(BlueprintType)
struct FKeychainSaveModel
{
	GENERATED_BODY()

	/** Name of the game. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GamerKeychain)
	FString GameName;

	/** Service name within the game. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GamerKeychain)
	FString Service;

	/** User in the game for which saving in keychain. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GamerKeychain)
	FString User;

	/** The password blob to save. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GamerKeychain)
	FString Password;
};
