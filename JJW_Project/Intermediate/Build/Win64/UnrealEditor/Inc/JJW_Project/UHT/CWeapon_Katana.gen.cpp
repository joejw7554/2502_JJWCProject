// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JJW_Project/Weapons/CWeapon_Katana.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCWeapon_Katana() {}

// Begin Cross Module References
JJW_PROJECT_API UClass* Z_Construct_UClass_ACWeapon_Katana();
JJW_PROJECT_API UClass* Z_Construct_UClass_ACWeapon_Katana_NoRegister();
JJW_PROJECT_API UClass* Z_Construct_UClass_ACWeaponBase();
UPackage* Z_Construct_UPackage__Script_JJW_Project();
// End Cross Module References

// Begin Class ACWeapon_Katana
void ACWeapon_Katana::StaticRegisterNativesACWeapon_Katana()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACWeapon_Katana);
UClass* Z_Construct_UClass_ACWeapon_Katana_NoRegister()
{
	return ACWeapon_Katana::StaticClass();
}
struct Z_Construct_UClass_ACWeapon_Katana_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/CWeapon_Katana.h" },
		{ "ModuleRelativePath", "Weapons/CWeapon_Katana.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACWeapon_Katana>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACWeapon_Katana_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACWeaponBase,
	(UObject* (*)())Z_Construct_UPackage__Script_JJW_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACWeapon_Katana_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACWeapon_Katana_Statics::ClassParams = {
	&ACWeapon_Katana::StaticClass,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACWeapon_Katana_Statics::Class_MetaDataParams), Z_Construct_UClass_ACWeapon_Katana_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACWeapon_Katana()
{
	if (!Z_Registration_Info_UClass_ACWeapon_Katana.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACWeapon_Katana.OuterSingleton, Z_Construct_UClass_ACWeapon_Katana_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACWeapon_Katana.OuterSingleton;
}
template<> JJW_PROJECT_API UClass* StaticClass<ACWeapon_Katana>()
{
	return ACWeapon_Katana::StaticClass();
}
ACWeapon_Katana::ACWeapon_Katana() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACWeapon_Katana);
ACWeapon_Katana::~ACWeapon_Katana() {}
// End Class ACWeapon_Katana

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CWeapon_Katana_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACWeapon_Katana, ACWeapon_Katana::StaticClass, TEXT("ACWeapon_Katana"), &Z_Registration_Info_UClass_ACWeapon_Katana, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACWeapon_Katana), 2630698114U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CWeapon_Katana_h_565648422(TEXT("/Script/JJW_Project"),
	Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CWeapon_Katana_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Weapons_CWeapon_Katana_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
