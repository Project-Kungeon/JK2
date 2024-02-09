// Copyright 2024 All Rights Reserved by J&K
#include "JK2AssetManager.h"

// #4
#include UE_INLINE_GENERATED_CPP_BY_NAME(JK2AssetManager)

UJK2AssetManager::UJK2AssetManager()
// #5
	: Super()
{
}

UJK2AssetManager& UJK2AssetManager::Get()
{
	check(GEngine);

	// AssetManager를 UEngine의 GEngine의 AssetManager의 Class를 오버라이드 했기 때문에, GEngine에 Asset Manager가 있음
	if (UJK2AssetManager* Singleton = Cast< UJK2AssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}

	UE_LOG(LogTemp, Fatal, TEXT("invalid AssetManagerClassname in DefaultEngine.ini(Project settings); it must be LyraClonAssetManager"));

	// 위의 UE_Log Fatal로 인해, Crash 나기 때문에 도달하지 않지만 컴파일을 위해 더미로 시전
	return *NewObject<UJK2AssetManager>();
}

void UJK2AssetManager::AddLoadedAsset(const UObject* Asset)
{
	if (ensureAlways(Asset))
	{
		FScopeLock Lock(&SyncObject);
		LoadedAssets.Add(Asset);
	}
}


PRAGMA_DISABLE_OPTIMIZATION
bool UJK2AssetManager::TestClone()
{
	static bool bTest = ShouldLogAssetLoads();
	return true;
}

bool UJK2AssetManager::ShouldLogAssetLoads()
{
	// 알아두면 좋을 점 두 가지
	// 1. FParse::Param과 FCommandLine::Get()을 통해, 원하는 속성 값을 CommandLine으로 가져올 수 있다
	//	  - 한 번 TestClone을 통해 실습해보자
	// 2. 함수 안에 static 변수 선언이다:
	//	  - 언리얼에서 자주 보는 패턴으로, 보통 글로벌 변수를 선언하고 싶은 경우, 두가지 옵션이 있다:
	//	    1. .h 파일에 extern을 선언하여, 헤더파일을 포함시키거나
	//		2. static 함수를  선언하여, 해당 함수 안에 static 변수를 선언하여, 반환하는 방법 (대표적인 예시로는 Singleton 패턴이 있다)		
	const TCHAR* commandLineContent = FCommandLine::Get();
	static bool bLogAssetLoads = FParse::Param(commandLineContent, TEXT("LogAssetLoads"));
	return bLogAssetLoads;
}
PRAGMA_ENABLE_OPTIMIZATION

UObject* UJK2AssetManager::SynchronousLoadAsset(const FSoftObjectPath& AssetPath)
{
	// 해당 함수를 따로 만든 이유는 'synchronous load asset이 불필요하게 하는 것이 없는 지 확인하기 위함'
	if (AssetPath.IsValid())
	{
		// FScopeLogTime을 확인해보자:
		TUniquePtr<FScopeLogTime> LogTimePtr;
		if (ShouldLogAssetLoads())
		{
			// 단순히 로깅하면서, 초단위로 로깅 실행
			LogTimePtr = MakeUnique<FScopeLogTime>(*FString::Printf(TEXT("synchronous loaded assets [%s]"), *AssetPath.ToString()), nullptr, FScopeLogTime::ScopeLog_Seconds);
		}

		// 여기서 두 가지 분기
		// 1. AssetManager가 있으면, AssetManager의 StreamableManager를 통해 정적 로깅
		// 2. 아니면, FSoftObjectPath를 통해 바로 정적 로깅
		if (UAssetManager::IsValid())
		{
			return UAssetManager::GetStreamableManager().LoadSynchronous(AssetPath);
		}

		// if asset manager is not ready, use LoadObject()
		// - TryLoad를 슥 보면. StaticLoadObject가 보인다:
		// - 참고로, 항상 StaticLoadObject하기 전에 StaticFindObject를 통해 확인하고 실패하면 로딩함
		return AssetPath.TryLoad();
	}

	return nullptr;
}

void UJK2AssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	// 로깅만 하고 지나가자
	UE_LOG(LogTemp, Display, TEXT("ULyraAssetManager::StartInitLoading"));
}
