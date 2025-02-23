// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JJW_Project/Player/CPlayerAnim.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPlayerAnim() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCPlayerAnim();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCPlayerAnim_NoRegister();
UPackage* Z_Construct_UPackage__Script_JJW_Project();
// End Cross Module References

// Begin Class UCPlayerAnim
void UCPlayerAnim::StaticRegisterNativesUCPlayerAnim()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCPlayerAnim);
UClass* Z_Construct_UClass_UCPlayerAnim_NoRegister()
{
	return UCPlayerAnim::StaticClass();
}
struct Z_Construct_UClass_UCPlayerAnim_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "Player/CPlayerAnim.h" },
		{ "ModuleRelativePath", "Player/CPlayerAnim.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCPlayerAnim>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCPlayerAnim_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_JJW_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCPlayerAnim_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCPlayerAnim_Statics::ClassParams = {
	&UCPlayerAnim::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCPlayerAnim_Statics::Class_MetaDataParams), Z_Construct_UClass_UCPlayerAnim_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCPlayerAnim()
{
	if (!Z_Registration_Info_UClass_UCPlayerAnim.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCPlayerAnim.OuterSingleton, Z_Construct_UClass_UCPlayerAnim_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCPlayerAnim.OuterSingleton;
}
template<> JJW_PROJECT_API UClass* StaticClass<UCPlayerAnim>()
{
	return UCPlayerAnim::StaticClass();
}
UCPlayerAnim::UCPlayerAnim(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCPlayerAnim);
UCPlayerAnim::~UCPlayerAnim() {}
// End Class UCPlayerAnim

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayerAnim_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCPlayerAnim, UCPlayerAnim::StaticClass, TEXT("UCPlayerAnim"), &Z_Registration_Info_UClass_UCPlayerAnim, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCPlayerAnim), 3091258020U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayerAnim_h_364275167(TEXT("/Script/JJW_Project"),
	Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayerAnim_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayerAnim_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
