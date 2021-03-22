// Copyright 2021 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Model/KeychainReadModel.h"
#include "Model/KeychainSaveModel.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "GamerKeychainProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSaveCallback, bool, Successful);

/**
 * 
 */
UCLASS()
class GAMERKEYCHAIN_API USaveGamerKeychainProxy : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = GamerKeychain)
	FSaveCallback OnSaved;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = GamerKeychain)
	static USaveGamerKeychainProxy* SaveInKeychain(const FKeychainSaveModel KeychainValue);
	virtual void Activate() override;
private:
	FKeychainSaveModel KeychainSaveModel;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FReadCallback, bool, Successful, FString, Value);

/**
* 
*/
UCLASS()
class GAMERKEYCHAIN_API UReadGamerKeychainProxy : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = GamerKeychain)
	FReadCallback OnRead;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = GamerKeychain)
	static UReadGamerKeychainProxy* ReadFromKeychain(const FKeychainReadModel KeychainValue);
	virtual void Activate() override;
private:
	FKeychainReadModel KeychainReadModel;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeleteCallback, bool, Successful);

/**
* 
*/
UCLASS()
class GAMERKEYCHAIN_API UDeleteGamerKeychainProxy : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = GamerKeychain)
	FDeleteCallback OnDelete;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = GamerKeychain)
	static UDeleteGamerKeychainProxy* DeleteFromKeychain(const FKeychainReadModel KeychainValue);
	virtual void Activate() override;
private:
	FKeychainReadModel KeychainReadModel;
};
