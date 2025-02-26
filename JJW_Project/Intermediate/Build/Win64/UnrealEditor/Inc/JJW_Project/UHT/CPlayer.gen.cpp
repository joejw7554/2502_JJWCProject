// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JJW_Project/Player/CPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPlayer() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
JJW_PROJECT_API UClass* Z_Construct_UClass_ACPlayer();
JJW_PROJECT_API UClass* Z_Construct_UClass_ACPlayer_NoRegister();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCMovementComponent_NoRegister();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCStateComponent_NoRegister();
JJW_PROJECT_API UEnum* Z_Construct_UEnum_JJW_Project_EState();
UPackage* Z_Construct_UPackage__Script_JJW_Project();
// End Cross Module References

// Begin Class ACPlayer Function OnStateChanged
struct Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics
{
	struct CPlayer_eventOnStateChanged_Parms
	{
		EState InPrevState;
		EState InNewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_InPrevState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InPrevState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InNewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InNewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::NewProp_InPrevState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::NewProp_InPrevState = { "InPrevState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPlayer_eventOnStateChanged_Parms, InPrevState), Z_Construct_UEnum_JJW_Project_EState, METADATA_PARAMS(0, nullptr) }; // 4127908453
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::NewProp_InNewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::NewProp_InNewState = { "InNewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPlayer_eventOnStateChanged_Parms, InNewState), Z_Construct_UEnum_JJW_Project_EState, METADATA_PARAMS(0, nullptr) }; // 4127908453
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::NewProp_InPrevState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::NewProp_InPrevState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::NewProp_InNewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::NewProp_InNewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPlayer, nullptr, "OnStateChanged", nullptr, nullptr, Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::CPlayer_eventOnStateChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::CPlayer_eventOnStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPlayer_OnStateChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPlayer_OnStateChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPlayer::execOnStateChanged)
{
	P_GET_ENUM(EState,Z_Param_InPrevState);
	P_GET_ENUM(EState,Z_Param_InNewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnStateChanged(EState(Z_Param_InPrevState),EState(Z_Param_InNewState));
	P_NATIVE_END;
}
// End Class ACPlayer Function OnStateChanged

// Begin Class ACPlayer
void ACPlayer::StaticRegisterNativesACPlayer()
{
	UClass* Class = ACPlayer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnStateChanged", &ACPlayer::execOnStateChanged },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPlayer);
UClass* Z_Construct_UClass_ACPlayer_NoRegister()
{
	return ACPlayer::StaticClass();
}
struct Z_Construct_UClass_ACPlayer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/CPlayer.h" },
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_MoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_LookAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_SprintAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_DodgeAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "Category", "CPlayer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
		{ "Category", "CPlayer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Movement_MetaData[] = {
		{ "Category", "CPlayer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "CPlayer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Player/CPlayer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_SprintAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_DodgeAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Movement;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_State;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACPlayer_OnStateChanged, "OnStateChanged" }, // 4241904994
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPlayer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPlayer, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMappingContext_MetaData), NewProp_InputMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_IA_MoveAction = { "IA_MoveAction", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPlayer, IA_MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_MoveAction_MetaData), NewProp_IA_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_IA_LookAction = { "IA_LookAction", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPlayer, IA_LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_LookAction_MetaData), NewProp_IA_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_IA_SprintAction = { "IA_SprintAction", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPlayer, IA_SprintAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_SprintAction_MetaData), NewProp_IA_SprintAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_IA_DodgeAction = { "IA_DodgeAction", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPlayer, IA_DodgeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_DodgeAction_MetaData), NewProp_IA_DodgeAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPlayer, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPlayer, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FollowCamera_MetaData), NewProp_FollowCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_Movement = { "Movement", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPlayer, Movement), Z_Construct_UClass_UCMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Movement_MetaData), NewProp_Movement_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPlayer_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPlayer, State), Z_Construct_UClass_UCStateComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPlayer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_InputMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_IA_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_IA_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_IA_SprintAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_IA_DodgeAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_FollowCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_Movement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPlayer_Statics::NewProp_State,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPlayer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACPlayer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_JJW_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPlayer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPlayer_Statics::ClassParams = {
	&ACPlayer::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACPlayer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACPlayer_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPlayer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACPlayer()
{
	if (!Z_Registration_Info_UClass_ACPlayer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPlayer.OuterSingleton, Z_Construct_UClass_ACPlayer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACPlayer.OuterSingleton;
}
template<> JJW_PROJECT_API UClass* StaticClass<ACPlayer>()
{
	return ACPlayer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACPlayer);
ACPlayer::~ACPlayer() {}
// End Class ACPlayer

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACPlayer, ACPlayer::StaticClass, TEXT("ACPlayer"), &Z_Registration_Info_UClass_ACPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPlayer), 3168698330U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_4049188525(TEXT("/Script/JJW_Project"),
	Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
