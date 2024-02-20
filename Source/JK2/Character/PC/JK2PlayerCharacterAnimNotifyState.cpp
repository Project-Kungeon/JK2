// Copyright 2024 All Rights Reserved by J&K


#include "JK2PlayerCharacterAnimNotifyState.h"
#include "JK2PlayerCharacter.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(JK2PlayerCharacterAnimNotifyState)

void UJK2PlayerCharacterAnimNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if ( AJK2PlayerCharacter* PlayerCharacter = Cast<AJK2PlayerCharacter>(MeshComp->GetOwner()) )
	{
		PlayerCharacter->bWeaponActive = true;
	}
}

void UJK2PlayerCharacterAnimNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if ( AJK2PlayerCharacter* PlayerCharacter = Cast<AJK2PlayerCharacter>(MeshComp->GetOwner()) )
	{
		PlayerCharacter->bWeaponActive = false;
		PlayerCharacter->WeaponAttackTargets.Empty();
	}
}
