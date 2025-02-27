// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJJW_Project_init() {}
	JJW_PROJECT_API UFunction* Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_JJW_Project;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_JJW_Project()
	{
		if (!Z_Registration_Info_UPackage__Script_JJW_Project.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/JJW_Project",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xAAB5AB85,
				0x492BFE1B,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_JJW_Project.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_JJW_Project.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_JJW_Project(Z_Construct_UPackage__Script_JJW_Project, TEXT("/Script/JJW_Project"), Z_Registration_Info_UPackage__Script_JJW_Project, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xAAB5AB85, 0x492BFE1B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
