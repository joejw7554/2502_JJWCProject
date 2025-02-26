// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/CWeaponComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef JJW_PROJECT_CWeaponComponent_generated_h
#error "CWeaponComponent.generated.h already included, missing '#pragma once' in CWeaponComponent.h"
#endif
#define JJW_PROJECT_CWeaponComponent_generated_h

#define FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCWeaponComponent(); \
	friend struct Z_Construct_UClass_UCWeaponComponent_Statics; \
public: \
	DECLARE_CLASS(UCWeaponComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JJW_Project"), NO_API) \
	DECLARE_SERIALIZER(UCWeaponComponent)


#define FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCWeaponComponent(UCWeaponComponent&&); \
	UCWeaponComponent(const UCWeaponComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCWeaponComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCWeaponComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCWeaponComponent) \
	NO_API virtual ~UCWeaponComponent();


#define FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_15_PROLOG
#define FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> JJW_PROJECT_API UClass* StaticClass<class UCWeaponComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h


#define FOREACH_ENUM_EWEAPONTYPE(op) \
	op(EWeaponType::Katana) 

enum class EWeaponType : uint8;
template<> struct TIsUEnumClass<EWeaponType> { enum { Value = true }; };
template<> JJW_PROJECT_API UEnum* StaticEnum<EWeaponType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
