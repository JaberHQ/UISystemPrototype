// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UISystemPrototype/UISystemPrototypeGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUISystemPrototypeGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UISYSTEMPROTOTYPE_API UClass* Z_Construct_UClass_AUISystemPrototypeGameMode();
	UISYSTEMPROTOTYPE_API UClass* Z_Construct_UClass_AUISystemPrototypeGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UISystemPrototype();
// End Cross Module References
	void AUISystemPrototypeGameMode::StaticRegisterNativesAUISystemPrototypeGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUISystemPrototypeGameMode);
	UClass* Z_Construct_UClass_AUISystemPrototypeGameMode_NoRegister()
	{
		return AUISystemPrototypeGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AUISystemPrototypeGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUISystemPrototypeGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UISystemPrototype,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUISystemPrototypeGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "UISystemPrototypeGameMode.h" },
		{ "ModuleRelativePath", "UISystemPrototypeGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUISystemPrototypeGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUISystemPrototypeGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AUISystemPrototypeGameMode_Statics::ClassParams = {
		&AUISystemPrototypeGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AUISystemPrototypeGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AUISystemPrototypeGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AUISystemPrototypeGameMode()
	{
		if (!Z_Registration_Info_UClass_AUISystemPrototypeGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUISystemPrototypeGameMode.OuterSingleton, Z_Construct_UClass_AUISystemPrototypeGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AUISystemPrototypeGameMode.OuterSingleton;
	}
	template<> UISYSTEMPROTOTYPE_API UClass* StaticClass<AUISystemPrototypeGameMode>()
	{
		return AUISystemPrototypeGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUISystemPrototypeGameMode);
	AUISystemPrototypeGameMode::~AUISystemPrototypeGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_Jaber_Documents_GitHub_UISystemPrototype_UISystemPrototype_Source_UISystemPrototype_UISystemPrototypeGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Jaber_Documents_GitHub_UISystemPrototype_UISystemPrototype_Source_UISystemPrototype_UISystemPrototypeGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AUISystemPrototypeGameMode, AUISystemPrototypeGameMode::StaticClass, TEXT("AUISystemPrototypeGameMode"), &Z_Registration_Info_UClass_AUISystemPrototypeGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUISystemPrototypeGameMode), 1329055249U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Jaber_Documents_GitHub_UISystemPrototype_UISystemPrototype_Source_UISystemPrototype_UISystemPrototypeGameMode_h_2707725292(TEXT("/Script/UISystemPrototype"),
		Z_CompiledInDeferFile_FID_Users_Jaber_Documents_GitHub_UISystemPrototype_UISystemPrototype_Source_UISystemPrototype_UISystemPrototypeGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Jaber_Documents_GitHub_UISystemPrototype_UISystemPrototype_Source_UISystemPrototype_UISystemPrototypeGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
