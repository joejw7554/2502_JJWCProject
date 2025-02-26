// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/CPlayer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EState : uint8;
#ifdef JJW_PROJECT_CPlayer_generated_h
#error "CPlayer.generated.h already included, missing '#pragma once' in CPlayer.h"
#endif
#define JJW_PROJECT_CPlayer_generated_h

#define FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnStateChanged);


#define FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACPlayer(); \
	friend struct Z_Construct_UClass_ACPlayer_Statics; \
public: \
	DECLARE_CLASS(ACPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JJW_Project"), NO_API) \
	DECLARE_SERIALIZER(ACPlayer)


#define FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACPlayer(ACPlayer&&); \
	ACPlayer(const ACPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPlayer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACPlayer) \
	NO_API virtual ~ACPlayer();


#define FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_11_PROLOG
#define FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> JJW_PROJECT_API UClass* StaticClass<class ACPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Player_CPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
