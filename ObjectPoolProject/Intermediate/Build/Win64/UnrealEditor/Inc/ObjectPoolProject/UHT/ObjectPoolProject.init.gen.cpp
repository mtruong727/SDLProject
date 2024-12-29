// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectPoolProject_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ObjectPoolProject;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ObjectPoolProject()
	{
		if (!Z_Registration_Info_UPackage__Script_ObjectPoolProject.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ObjectPoolProject",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x44B9187D,
				0x54D71B7B,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ObjectPoolProject.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ObjectPoolProject.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ObjectPoolProject(Z_Construct_UPackage__Script_ObjectPoolProject, TEXT("/Script/ObjectPoolProject"), Z_Registration_Info_UPackage__Script_ObjectPoolProject, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x44B9187D, 0x54D71B7B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
