// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JJW_Project/Weapons/CWeaponBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCWeaponBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
JJW_PROJECT_API UClass* Z_Construct_UClass_ACWeaponBase();
JJW_PROJECT_API UClass* Z_Construct_UClass_ACWeaponBase_NoRegister();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCSkillComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JJW_Project();
// End Cross Module References

// Begin Class ACWeaponBase
void ACWeaponBase::StaticRegisterNativesACWeaponBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACWeaponBase);
UClass* Z_Construct_UClass_ACWeaponBase_NoRegister()
{
	return ACWeaponBase::StaticClass();
}
struct Z_Construct_UClass_ACWeaponBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/CWeaponBase.h" },
		{ "ModuleRelativePath", "Weapons/CWeaponBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[] = {
		{ "Category", "CWeaponBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapons/CWeaponBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkillComponent_MetaData[] = {
		{ "Category", "CWeaponBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapons/CWeaponBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocketName_RightHand_MetaData[] = {
		{ "Category", "CWeaponBase" },
		{ "ModuleRelativePath", "Weapons/CWeaponBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocketName_LeftHand_MetaData[] = {
		{ "Category", "CWeaponBase" },
		{ "ModuleRelativePath", "Weapons/CWeaponBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocketName_WeaponHolster_MetaData[] = {
		{ "Category", "CWeaponBase" },
		{ "ModuleRelativePath", "Weapons/CWeaponBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Root;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SkillComponent;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SocketName_RightHand;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SocketName_LeftHand;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SocketName_WeaponHolster;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACWeaponBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACWeaponBase_Statics::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACWeaponBase, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Root_MetaData), NewProp_Root_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACWeaponBase_Statics::NewProp_SkillComponent = { "SkillComponent", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACWeaponBase, SkillComponent), Z_Construct_UClass_UCSkillComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkillComponent_MetaData), NewProp_SkillComponent_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ACWeaponBase_Statics::NewProp_SocketName_RightHand = { "SocketName_RightHand", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACWeaponBase, SocketName_RightHand), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocketName_RightHand_MetaData), NewProp_SocketName_RightHand_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ACWeaponBase_Statics::NewProp_SocketName_LeftHand = { "SocketName_LeftHand", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACWeaponBase, SocketName_LeftHand), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocketName_LeftHand_MetaData), NewProp_SocketName_LeftHand_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ACWeaponBase_Statics::NewProp_SocketName_WeaponHolster = { "SocketName_WeaponHolster", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACWeaponBase, SocketName_WeaponHolster), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocketName_WeaponHolster_MetaData), NewProp_SocketName_WeaponHolster_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACWeaponBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACWeaponBase_Statics::NewProp_Root,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACWeaponBase_Statics::NewProp_SkillComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACWeaponBase_Statics::NewProp_SocketName_RightHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACWeaponBase_Statics::NewProp_SocketName_LeftHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACWeaponBase_Statics::NewProp_SocketName_WeaponHolster,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACWeaponBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACWeaponBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_JJW_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACWeaponBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACWeaponBase_Statics::ClassParams = {
	&ACWeaponBase::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACWeaponBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACWeaponBase_Statics::PropPointers),
	0,
	0x009000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACWeaponBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ACWeaponBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACWeaponBase()
{
	if (!Z_Registration_Info_UClass_ACWeaponBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACWeaponBase.OuterSingleton, Z_Construct_UClass_ACWeaponBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACWeaponBase.OuterSingleton;
}
template<> JJW_PROJECT_API UClass* StaticClass<ACWeaponBase>()
{
	return ACWeaponBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACWeaponBase);
ACWeaponBase::~ACWeaponBase() {}
// End Class ACWeaponBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CWeaponBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACWeaponBase, ACWeaponBase::StaticClass, TEXT("ACWeaponBase"), &Z_Registration_Info_UClass_ACWeaponBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACWeaponBase), 497863052U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CWeaponBase_h_674730797(TEXT("/Script/JJW_Project"),
	Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CWeaponBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CWeaponBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
