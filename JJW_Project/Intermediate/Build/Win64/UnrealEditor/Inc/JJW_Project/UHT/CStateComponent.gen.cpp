// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JJW_Project/Components/CStateComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCStateComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCStateComponent();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCStateComponent_NoRegister();
JJW_PROJECT_API UEnum* Z_Construct_UEnum_JJW_Project_EState();
JJW_PROJECT_API UFunction* Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_JJW_Project();
// End Cross Module References

// Begin Enum EState
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EState;
static UEnum* EState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JJW_Project_EState, (UObject*)Z_Construct_UPackage__Script_JJW_Project(), TEXT("EState"));
	}
	return Z_Registration_Info_UEnum_EState.OuterSingleton;
}
template<> JJW_PROJECT_API UEnum* StaticEnum<EState>()
{
	return EState_StaticEnum();
}
struct Z_Construct_UEnum_JJW_Project_EState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Attack.Name", "EState::Attack" },
		{ "Damaged.Name", "EState::Damaged" },
		{ "Dead.Name", "EState::Dead" },
		{ "Dodge.Name", "EState::Dodge" },
		{ "Idle.Name", "EState::Idle" },
		{ "Max.Name", "EState::Max" },
		{ "ModuleRelativePath", "Components/CStateComponent.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EState::Idle", (int64)EState::Idle },
		{ "EState::Attack", (int64)EState::Attack },
		{ "EState::Dodge", (int64)EState::Dodge },
		{ "EState::Damaged", (int64)EState::Damaged },
		{ "EState::Dead", (int64)EState::Dead },
		{ "EState::Max", (int64)EState::Max },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JJW_Project_EState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JJW_Project,
	nullptr,
	"EState",
	"EState",
	Z_Construct_UEnum_JJW_Project_EState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JJW_Project_EState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JJW_Project_EState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JJW_Project_EState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JJW_Project_EState()
{
	if (!Z_Registration_Info_UEnum_EState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EState.InnerSingleton, Z_Construct_UEnum_JJW_Project_EState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EState.InnerSingleton;
}
// End Enum EState

// Begin Delegate FStateChange
struct Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics
{
	struct _Script_JJW_Project_eventStateChange_Parms
	{
		EState InPrevState;
		EState InNewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/CStateComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_InPrevState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InPrevState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InNewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InNewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::NewProp_InPrevState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::NewProp_InPrevState = { "InPrevState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JJW_Project_eventStateChange_Parms, InPrevState), Z_Construct_UEnum_JJW_Project_EState, METADATA_PARAMS(0, nullptr) }; // 4127908453
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::NewProp_InNewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::NewProp_InNewState = { "InNewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JJW_Project_eventStateChange_Parms, InNewState), Z_Construct_UEnum_JJW_Project_EState, METADATA_PARAMS(0, nullptr) }; // 4127908453
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::NewProp_InPrevState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::NewProp_InPrevState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::NewProp_InNewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::NewProp_InNewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_JJW_Project, nullptr, "StateChange__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::_Script_JJW_Project_eventStateChange_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::_Script_JJW_Project_eventStateChange_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JJW_Project_StateChange__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FStateChange_DelegateWrapper(const FMulticastScriptDelegate& StateChange, EState InPrevState, EState InNewState)
{
	struct _Script_JJW_Project_eventStateChange_Parms
	{
		EState InPrevState;
		EState InNewState;
	};
	_Script_JJW_Project_eventStateChange_Parms Parms;
	Parms.InPrevState=InPrevState;
	Parms.InNewState=InNewState;
	StateChange.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FStateChange

// Begin Class UCStateComponent
void UCStateComponent::StaticRegisterNativesUCStateComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCStateComponent);
UClass* Z_Construct_UClass_UCStateComponent_NoRegister()
{
	return UCStateComponent::StaticClass();
}
struct Z_Construct_UClass_UCStateComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Components/CStateComponent.h" },
		{ "ModuleRelativePath", "Components/CStateComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCStateComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCStateComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JJW_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCStateComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCStateComponent_Statics::ClassParams = {
	&UCStateComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCStateComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCStateComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCStateComponent()
{
	if (!Z_Registration_Info_UClass_UCStateComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCStateComponent.OuterSingleton, Z_Construct_UClass_UCStateComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCStateComponent.OuterSingleton;
}
template<> JJW_PROJECT_API UClass* StaticClass<UCStateComponent>()
{
	return UCStateComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCStateComponent);
UCStateComponent::~UCStateComponent() {}
// End Class UCStateComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EState_StaticEnum, TEXT("EState"), &Z_Registration_Info_UEnum_EState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4127908453U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCStateComponent, UCStateComponent::StaticClass, TEXT("UCStateComponent"), &Z_Registration_Info_UClass_UCStateComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCStateComponent), 1798900491U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_2463897360(TEXT("/Script/JJW_Project"),
	Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
