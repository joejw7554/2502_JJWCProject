// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JJW_Project/Components/CWeaponComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCWeaponComponent() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JJW_PROJECT_API UClass* Z_Construct_UClass_ACWeaponBase_NoRegister();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCWeaponComponent();
JJW_PROJECT_API UClass* Z_Construct_UClass_UCWeaponComponent_NoRegister();
JJW_PROJECT_API UEnum* Z_Construct_UEnum_JJW_Project_EWeaponType();
UPackage* Z_Construct_UPackage__Script_JJW_Project();
// End Cross Module References

// Begin Enum EWeaponType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EWeaponType;
static UEnum* EWeaponType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EWeaponType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EWeaponType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JJW_Project_EWeaponType, (UObject*)Z_Construct_UPackage__Script_JJW_Project(), TEXT("EWeaponType"));
	}
	return Z_Registration_Info_UEnum_EWeaponType.OuterSingleton;
}
template<> JJW_PROJECT_API UEnum* StaticEnum<EWeaponType>()
{
	return EWeaponType_StaticEnum();
}
struct Z_Construct_UEnum_JJW_Project_EWeaponType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Delegate\xec\x82\xac\xec\x9a\xa9\xed\x95\xb4\xec\x84\x9c \xec\x9b\xa8\xed\x8f\xb0\xec\x97\x90 \xeb\xaa\x85\xeb\xa0\xb9\xec\x9d\x84 \xeb\x82\xb4\xeb\xa6\xb4\xea\xb9\x8c?\n" },
#endif
		{ "Katana.Name", "EWeaponType::Katana" },
		{ "ModuleRelativePath", "Components/CWeaponComponent.h" },
		{ "None.Name", "EWeaponType::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate\xec\x82\xac\xec\x9a\xa9\xed\x95\xb4\xec\x84\x9c \xec\x9b\xa8\xed\x8f\xb0\xec\x97\x90 \xeb\xaa\x85\xeb\xa0\xb9\xec\x9d\x84 \xeb\x82\xb4\xeb\xa6\xb4\xea\xb9\x8c?" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EWeaponType::None", (int64)EWeaponType::None },
		{ "EWeaponType::Katana", (int64)EWeaponType::Katana },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JJW_Project_EWeaponType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JJW_Project,
	nullptr,
	"EWeaponType",
	"EWeaponType",
	Z_Construct_UEnum_JJW_Project_EWeaponType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JJW_Project_EWeaponType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JJW_Project_EWeaponType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JJW_Project_EWeaponType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JJW_Project_EWeaponType()
{
	if (!Z_Registration_Info_UEnum_EWeaponType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EWeaponType.InnerSingleton, Z_Construct_UEnum_JJW_Project_EWeaponType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EWeaponType.InnerSingleton;
}
// End Enum EWeaponType

// Begin Class UCWeaponComponent
void UCWeaponComponent::StaticRegisterNativesUCWeaponComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCWeaponComponent);
UClass* Z_Construct_UClass_UCWeaponComponent_NoRegister()
{
	return UCWeaponComponent::StaticClass();
}
struct Z_Construct_UClass_UCWeaponComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Components/CWeaponComponent.h" },
		{ "ModuleRelativePath", "Components/CWeaponComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponClassToSpawn_MetaData[] = {
		{ "Category", "Weapons" },
		{ "ModuleRelativePath", "Components/CWeaponComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveWeapons_MetaData[] = {
		{ "Category", "Weapons" },
		{ "ModuleRelativePath", "Components/CWeaponComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWeaponType_MetaData[] = {
		{ "Category", "Value Debug" },
		{ "ModuleRelativePath", "Components/CWeaponComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWeapon_MetaData[] = {
		{ "Category", "Value Debug" },
		{ "ModuleRelativePath", "Components/CWeaponComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Owner_MetaData[] = {
		{ "Category", "Value Debug" },
		{ "ModuleRelativePath", "Components/CWeaponComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_WeaponClassToSpawn_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_WeaponClassToSpawn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveWeapons_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveWeapons;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentWeaponType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentWeaponType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentWeapon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Owner;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCWeaponComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_WeaponClassToSpawn_Inner = { "WeaponClassToSpawn", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_ACWeaponBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_WeaponClassToSpawn = { "WeaponClassToSpawn", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCWeaponComponent, WeaponClassToSpawn), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponClassToSpawn_MetaData), NewProp_WeaponClassToSpawn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_ActiveWeapons_Inner = { "ActiveWeapons", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ACWeaponBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_ActiveWeapons = { "ActiveWeapons", nullptr, (EPropertyFlags)0x0020080000020001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCWeaponComponent, ActiveWeapons), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveWeapons_MetaData), NewProp_ActiveWeapons_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_CurrentWeaponType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_CurrentWeaponType = { "CurrentWeaponType", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCWeaponComponent, CurrentWeaponType), Z_Construct_UEnum_JJW_Project_EWeaponType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWeaponType_MetaData), NewProp_CurrentWeaponType_MetaData) }; // 3787469345
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_CurrentWeapon = { "CurrentWeapon", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCWeaponComponent, CurrentWeapon), Z_Construct_UClass_ACWeaponBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWeapon_MetaData), NewProp_CurrentWeapon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_Owner = { "Owner", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCWeaponComponent, Owner), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Owner_MetaData), NewProp_Owner_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCWeaponComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_WeaponClassToSpawn_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_WeaponClassToSpawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_ActiveWeapons_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_ActiveWeapons,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_CurrentWeaponType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_CurrentWeaponType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_CurrentWeapon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCWeaponComponent_Statics::NewProp_Owner,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCWeaponComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCWeaponComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JJW_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCWeaponComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCWeaponComponent_Statics::ClassParams = {
	&UCWeaponComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCWeaponComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCWeaponComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCWeaponComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCWeaponComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCWeaponComponent()
{
	if (!Z_Registration_Info_UClass_UCWeaponComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCWeaponComponent.OuterSingleton, Z_Construct_UClass_UCWeaponComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCWeaponComponent.OuterSingleton;
}
template<> JJW_PROJECT_API UClass* StaticClass<UCWeaponComponent>()
{
	return UCWeaponComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCWeaponComponent);
UCWeaponComponent::~UCWeaponComponent() {}
// End Class UCWeaponComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EWeaponType_StaticEnum, TEXT("EWeaponType"), &Z_Registration_Info_UEnum_EWeaponType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3787469345U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCWeaponComponent, UCWeaponComponent::StaticClass, TEXT("UCWeaponComponent"), &Z_Registration_Info_UClass_UCWeaponComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCWeaponComponent), 988467453U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_29146095(TEXT("/Script/JJW_Project"),
	Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Atents_Desktop_2502_JJWCProject_JJW_Project_Source_JJW_Project_Components_CWeaponComponent_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
