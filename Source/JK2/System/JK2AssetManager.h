// Copyright 2024 All Rights Reserved by J&K
// #1
#pragma once

#include "Engine/AssetManager.h"
// #2
#include "JK2AssetManager.generated.h"

UCLASS()
class UJK2AssetManager : public UAssetManager
{
	// #3
	GENERATED_BODY()
public:
	UJK2AssetManager();

	/** singleton 메서드 */
	static UJK2AssetManager& Get();

	/** [THREAD-SAFE] 메모리에 로딩된 에셋 캐싱 */
	void AddLoadedAsset(const UObject* Asset);

	/** 클론 코딩 과정에서 테스트를 위한 함수(및 테크닉) */
	static bool TestClone();

	/**
	* 해당 함수는 FScopeLogTime을 사용할지 않을지 유무 판단을 위해 사용
	* - 굳이 클론 코딩할 필요 없지만. 알아두면 좋은 점이 있다.
	*/
	static bool ShouldLogAssetLoads();

	/** ULyraCloneAssetManager가 로딩을 관장함을 알 수 있다*/
	static UObject* SynchronousLoadAsset(const FSoftObjectPath& AssetPath);

	/**
	* GetAsset은 정적 로딩으로 BP Class와 Object 로딩
	* - 주목해야 할 부분은 bKeepInMemory
	*/
	template <typename AssetType>
	static AssetType* GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer, bool bKeepsInMemory = true);

	template <typename AssetType>
	static TSubclassOf<AssetType> GetSubclass(const TSoftClassPtr<AssetType>& AssetPointer, bool bKeepInMemory = true);

	/**
	* UAssetManager's interfaces
	*/
	virtual void StartInitialLoading() final;

	/**
	* member variables
	*/
	// GC의 대상
	UPROPERTY()
	TSet<TObjectPtr<const UObject>> LoadedAssets;

	// Object 단위 Locking
	FCriticalSection SyncObject;
};

template<typename AssetType>
inline AssetType* UJK2AssetManager::GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer, bool bKeepsInMemory)
{
	AssetType* LoadedAsset = nullptr;
	const FSoftObjectPath& AssetPath = AssetPointer.ToSoftObjectPath();

	if (AssetPath.IsValid())
	{
		LoadedAsset = AssetPointer.Get();
		if (!LoadedAsset)
		{
			LoadedAsset = Cast<AssetType>(SynchronousLoadAsset(AssetPath));
			ensureAlwaysMsgf(LoadedAsset, TEXT("Failed to load asset [%s]"), *AssetPointer.ToString());
		}

		if (LoadedAsset && bKeepsInMemory)
		{
			// 여기서 AddLoadAsset은 메모리에 상주하기 위한 장치라고 생각하면 됨:
			// - 한 번 등록되면 직접 내리지 않는 한 unload가 되지 않음 (== 캐싱)
			Get().AddLoadedAsset(Cast<UObject>(LoadedAsset));
		}
	}

	return nullptr;
}

template<typename AssetType>
inline TSubclassOf<AssetType> UJK2AssetManager::GetSubclass(const TSoftClassPtr<AssetType>& AssetPointer, bool bKeepsInMemory)
{
	TSubclassOf<AssetType> LoadedSubclass;
	const FSoftObjectPath& AssetPath = AssetPointer.ToSoftObjectPath();

	if (AssetPath.IsValid())
	{
		LoadedSubclass = AssetPointer.Get();
		if (!LoadedSubclass)
		{
			LoadedSubclass = Cast<UClass>(SynchronousLoadAsset(AssetPath));
			ensureAlwaysMsgf(LoadedSubclass, TEXT("Failed to load asset class [%s]"), *AssetPointer.ToString());
		}

		if (LoadedSubclass && bKeepsInMemory)
		{
			Get().AddLoadedAsset(Cast<UObject>(LoadedAsset));
		}
	}

	return LoadedSubclass;
}
