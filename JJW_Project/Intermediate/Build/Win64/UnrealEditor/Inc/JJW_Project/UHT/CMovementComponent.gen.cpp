// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JJW_Project/Components/CMovementComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCMovementComponent() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCMovementComponent();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCMovementComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JJW_Project();
// End Cross Module References

// Begin Class UCMovementComponent
void UCMovementComponent::StaticRegisterNativesUCMovementComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCMovementComponent);
UClass* Z_Construct_UClass_UCMovementComponent_NoRegister()
{
	return UCMovementComponent::StaticClass();
}
struct Z_Construct_UClass_UCMovementComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Components/CMovementComponent.h" },
		{ "ModuleRelativePath", "Components/CMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchAngleLimit_MetaData[] = {
		{ "Category", "Camera Property" },
		{ "ModuleRelativePath", "Components/CMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Movement Property" },
		{ "ModuleRelativePath", "Components/CMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Movement Property" },
		{ "ModuleRelativePath", "Components/CMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimMontage_Dodge_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "////////Montage\n" },
#endif
		{ "ModuleRelativePath", "Components/CMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Montage" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_Dodge_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "Components/CMovementComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PitchAngleLimit;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimMontage_Dodge;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate_Dodge;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCMovementComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCMovementComponent_Statics::NewProp_PitchAngleLimit = { "PitchAngleLimit", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCMovementComponent, PitchAngleLimit), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchAngleLimit_MetaData), NewProp_PitchAngleLimit_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCMovementComponent_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCMovementComponent, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCMovementComponent_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCMovementComponent, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintSpeed_MetaData), NewProp_SprintSpeed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCMovementComponent_Statics::NewProp_AnimMontage_Dodge = { "AnimMontage_Dodge", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCMovementComponent, AnimMontage_Dodge), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimMontage_Dodge_MetaData), NewProp_AnimMontage_Dodge_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCMovementComponent_Statics::NewProp_PlayRate_Dodge = { "PlayRate_Dodge", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCMovementComponent, PlayRate_Dodge), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayRate_Dodge_MetaData), NewProp_PlayRate_Dodge_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCMovementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCMovementComponent_Statics::NewProp_PitchAngleLimit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCMovementComponent_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCMovementComponent_Statics::NewProp_SprintSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCMovementComponent_Statics::NewProp_AnimMontage_Dodge,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCMovementComponent_Statics::NewProp_PlayRate_Dodge,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCMovementComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCMovementComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JJW_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCMovementComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCMovementComponent_Statics::ClassParams = {
	&UCMovementComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCMovementComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCMovementComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCMovementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCMovementComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCMovementComponent()
{
	if (!Z_Registration_Info_UClass_UCMovementComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCMovementComponent.OuterSingleton, Z_Construct_UClass_UCMovementComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCMovementComponent.OuterSingleton;
}
template<> JJW_PROJECT_API UClass* StaticClass<UCMovementComponent>()
{
	return UCMovementComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCMovementComponent);
UCMovementComponent::~UCMovementComponent() {}
// End Class UCMovementComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CMovementComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCMovementComponent, UCMovementComponent::StaticClass, TEXT("UCMovementComponent"), &Z_Registration_Info_UClass_UCMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCMovementComponent), 243541544U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CMovementComponent_h_379091230(TEXT("/Script/JJW_Project"),
	Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CMovementComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CMovementComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
