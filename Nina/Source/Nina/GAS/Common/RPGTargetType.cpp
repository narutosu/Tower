// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPGTargetType.h"
#include "RPGGameplayAbility.h"
#include "Role/RoleBase.h"

void URPGTargetType::GetTargets_Implementation(ARoleBase* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const
{
	return;
}

// void URPGTargetType_UseOwner::GetTargets_Implementation(ARoleBase* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<const AActor*>& OutActors) const
// {
// 	OutActors.Add(TargetingCharacter);
// }
//
// void URPGTargetType_UseEventData::GetTargets_Implementation(ARoleBase* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<const AActor*>& OutActors) const
// {
// 	const FHitResult* FoundHitResult = EventData.ContextHandle.GetHitResult();
// 	if (FoundHitResult)
// 	{
// 		OutHitResults.Add(*FoundHitResult);
// 	}
// 	else if (EventData.Target)
// 	{
// 		OutActors.Add(EventData.Target);
// 	}
// }