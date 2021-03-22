// Copyright 2021 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "KeychainReadModel.generated.h"

USTRUCT(BlueprintType)
struct FKeychainReadModel
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
};
