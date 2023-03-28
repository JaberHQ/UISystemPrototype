// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUISystemPrototype_init() {}
	UISYSTEMPROTOTYPE_API UFunction* Z_Construct_UDelegateFunction_UISystemPrototype_OnPickUp__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UISystemPrototype;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UISystemPrototype()
	{
		if (!Z_Registration_Info_UPackage__Script_UISystemPrototype.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UISystemPrototype_OnPickUp__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UISystemPrototype",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xBD7AD6A9,
				0x1FFD9FC3,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UISystemPrototype.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UISystemPrototype.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UISystemPrototype(Z_Construct_UPackage__Script_UISystemPrototype, TEXT("/Script/UISystemPrototype"), Z_Registration_Info_UPackage__Script_UISystemPrototype, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xBD7AD6A9, 0x1FFD9FC3));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
