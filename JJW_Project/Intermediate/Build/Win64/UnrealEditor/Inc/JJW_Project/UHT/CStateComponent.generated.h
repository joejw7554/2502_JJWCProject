// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/CStateComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EState : uint8;
#ifdef JJW_PROJECT_CStateComponent_generated_h
#error "CStateComponent.generated.h already included, missing '#pragma once' in CStateComponent.h"
#endif
#define JJW_PROJECT_CStateComponent_generated_h

#define FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_14_DELEGATE \
JJW_PROJECT_API void FStateChange_DelegateWrapper(const FMulticastScriptDelegate& StateChange, EState InPrevState, EState InNewState);


#define FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCStateComponent(); \
	friend struct Z_Construct_UClass_UCStateComponent_Statics; \
public: \
	DECLARE_CLASS(UCStateComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JJW_Project"), NO_API) \
	DECLARE_SERIALIZER(UCStateComponent)


#define FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCStateComponent(UCStateComponent&&); \
	UCStateComponent(const UCStateComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCStateComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCStateComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCStateComponent) \
	NO_API virtual ~UCStateComponent();


#define FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_16_PROLOG
#define FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_19_INCLASS_NO_PURE_DECLS \
	FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> JJW_PROJECT_API UClass* StaticClass<class UCStateComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_joejw_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CStateComponent_h


#define FOREACH_ENUM_ESTATE(op) \
	op(EState::Idle) \
	op(EState::Attack) \
	op(EState::Dodge) \
	op(EState::Damaged) \
	op(EState::Dead) \
	op(EState::Max) 

enum class EState : uint8;
template<> struct TIsUEnumClass<EState> { enum { Value = true }; };
template<> JJW_PROJECT_API UEnum* StaticEnum<EState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
