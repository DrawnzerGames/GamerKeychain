//  Copyright 2022 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Model/KeychainReadModel.h"
#include "Model/KeychainSaveModel.h"
#include "UObject/NoExportTypes.h"
#include "GamerKeychainSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class GAMERKEYCHAIN_API UGamerKeychainSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	static UGamerKeychainSubsystem* Get();
	static bool SaveInKeychainSync(const FKeychainSaveModel& KeychainValue);
	static FString ReadFromKeychainSync(const FKeychainReadModel& KeychainValue);
	static bool DeleteFromKeychainSync(const FKeychainReadModel& KeychainValue);
protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	static UGamerKeychainSubsystem* Subsystem;
};
