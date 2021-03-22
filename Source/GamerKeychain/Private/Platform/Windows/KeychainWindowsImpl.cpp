// Copyright 2021 - Infinity DrawnzerGames, Inc. All Rights Reserved.

#include "Platform/Windows/KeychainWindowsImpl.h"
#include <Windows.h>
#include <wincred.h>
#include <intsafe.h>
#include <string>
#include "Kismet/KismetSystemLibrary.h"

static const DWORD kCredType = CRED_TYPE_GENERIC;

FString UKeychainWindowsImpl::ReadFromKeychain(FKeychainReadModel KeychainReadModel)
{
	const FString Target = MakeTarget(KeychainReadModel);
	CREDENTIAL* Credentials;
	const bool ReadResult = ::CredRead(*Target, kCredType, 0, &Credentials);
	if (ReadResult)
	{
		const auto Password = std::string(reinterpret_cast<char*>(Credentials->CredentialBlob), Credentials->CredentialBlobSize);
		return FString(Password.c_str());
	}
	return "";
}

bool UKeychainWindowsImpl::DeleteFromKeychain(FKeychainReadModel KeychainReadModel)
{
	const FString Target = MakeTarget(KeychainReadModel);
	return ::CredDelete(*Target, kCredType, 0);
}

bool UKeychainWindowsImpl::SaveInKeychain(FKeychainSaveModel KeychainSaveModel)
{
	CREDENTIAL Credentials = {0};
	Credentials.Type = CRED_TYPE_GENERIC;

	const FString Target = MakeTarget(KeychainSaveModel);
	Credentials.TargetName = const_cast<TCHAR*>(*Target);
	Credentials.UserName = const_cast<TCHAR*>(*KeychainSaveModel.User);
	Credentials.CredentialBlobSize = static_cast<DWORD>(KeychainSaveModel.Password.Len());

	const std::string PasswordString = std::string(TCHAR_TO_UTF8(*KeychainSaveModel.Password));
	// ReSharper disable once CppFunctionalStyleCast
	Credentials.CredentialBlob = LPBYTE(PasswordString.data());
	Credentials.Persist = CRED_PERSIST_LOCAL_MACHINE;
	const auto WriteResult = ::CredWrite(&Credentials, 0);
	return WriteResult;
}

FString UKeychainWindowsImpl::MakeTarget(FKeychainSaveModel KeychainSaveModel)
{
	FString GameName = KeychainSaveModel.GameName;
	if (GameName.Len() == 0)
	{
		GameName = UKismetSystemLibrary::GetGameName();
	}
	FString Service = KeychainSaveModel.Service;
	if (Service.Len() == 0)
	{
		Service = "KeychainService";
	}
	FString User = KeychainSaveModel.User;
	const FString Target = GameName.Append(":").Append(Service).Append(":").Append(User);
	return Target;
}


FString UKeychainWindowsImpl::MakeTarget(FKeychainReadModel KeychainReadModel)
{
	FString GameName = KeychainReadModel.GameName;
	if (GameName.Len() == 0)
	{
		GameName = UKismetSystemLibrary::GetGameName();
	}
	FString Service = KeychainReadModel.Service;
	if (Service.Len() == 0)
	{
		Service = "KeychainService";
	}
	FString User = KeychainReadModel.User;
	const FString Target = GameName.Append(":").Append(Service).Append(":").Append(User);
	return Target;
}
