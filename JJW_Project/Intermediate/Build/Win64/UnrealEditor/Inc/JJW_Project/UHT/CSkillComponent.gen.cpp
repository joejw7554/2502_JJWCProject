// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JJW_Project/Weapons/CSkillComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCSkillComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCSkillComponent();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCSkillComponent_NoRegister();
JJW_PROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSkillSet();
UPackage* Z_Construct_UPackage__Script_JJW_Project();
// End Cross Module References

// Begin ScriptStruct FSkillSet
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SkillSet;
class UScriptStruct* FSkillSet::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SkillSet.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SkillSet.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSkillSet, (UObject*)Z_Construct_UPackage__Script_JJW_Project(), TEXT("SkillSet"));
	}
	return Z_Registration_Info_UScriptStruct_SkillSet.OuterSingleton;
}
template<> JJW_PROJECT_API UScriptStruct* StaticStruct<FSkillSet>()
{
	return FSkillSet::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSkillSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Weapons/CSkillComponent.h" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSkillSet>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSkillSet_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JJW_Project,
	nullptr,
	&NewStructOps,
	"SkillSet",
	nullptr,
	0,
	sizeof(FSkillSet),
	alignof(FSkillSet),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSkillSet_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSkillSet_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSkillSet()
{
	if (!Z_Registration_Info_UScriptStruct_SkillSet.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SkillSet.InnerSingleton, Z_Construct_UScriptStruct_FSkillSet_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SkillSet.InnerSingleton;
}
// End ScriptStruct FSkillSet

// Begin Class UCSkillComponent
void UCSkillComponent::StaticRegisterNativesUCSkillComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCSkillComponent);
UClass* Z_Construct_UClass_UCSkillComponent_NoRegister()
{
	return UCSkillComponent::StaticClass();
}
struct Z_Construct_UClass_UCSkillComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/CSkillComponent.h" },
		{ "ModuleRelativePath", "Weapons/CSkillComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseAttckCombo_MetaData[] = {
		{ "Category", "CSkillComponent" },
		{ "ModuleRelativePath", "Weapons/CSkillComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkillList_MetaData[] = {
		{ "Category", "Skill Property" },
		{ "ModuleRelativePath", "Weapons/CSkillComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BaseAttckCombo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SkillList_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SkillList;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCSkillComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCSkillComponent_Statics::NewProp_BaseAttckCombo = { "BaseAttckCombo", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCSkillComponent, BaseAttckCombo), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseAttckCombo_MetaData), NewProp_BaseAttckCombo_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCSkillComponent_Statics::NewProp_SkillList_Inner = { "SkillList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSkillSet, METADATA_PARAMS(0, nullptr) }; // 539928199
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCSkillComponent_Statics::NewProp_SkillList = { "SkillList", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCSkillComponent, SkillList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkillList_MetaData), NewProp_SkillList_MetaData) }; // 539928199
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCSkillComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCSkillComponent_Statics::NewProp_BaseAttckCombo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCSkillComponent_Statics::NewProp_SkillList_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCSkillComponent_Statics::NewProp_SkillList,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCSkillComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCSkillComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JJW_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCSkillComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCSkillComponent_Statics::ClassParams = {
	&UCSkillComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCSkillComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCSkillComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCSkillComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCSkillComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCSkillComponent()
{
	if (!Z_Registration_Info_UClass_UCSkillComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCSkillComponent.OuterSingleton, Z_Construct_UClass_UCSkillComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCSkillComponent.OuterSingleton;
}
template<> JJW_PROJECT_API UClass* StaticClass<UCSkillComponent>()
{
	return UCSkillComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCSkillComponent);
UCSkillComponent::~UCSkillComponent() {}
// End Class UCSkillComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CSkillComponent_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSkillSet::StaticStruct, Z_Construct_UScriptStruct_FSkillSet_Statics::NewStructOps, TEXT("SkillSet"), &Z_Registration_Info_UScriptStruct_SkillSet, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSkillSet), 539928199U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCSkillComponent, UCSkillComponent::StaticClass, TEXT("UCSkillComponent"), &Z_Registration_Info_UClass_UCSkillComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCSkillComponent), 4279584549U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CSkillComponent_h_1711188560(TEXT("/Script/JJW_Project"),
	Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CSkillComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CSkillComponent_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CSkillComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CSkillComponent_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
