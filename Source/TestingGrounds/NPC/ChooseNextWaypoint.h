// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:

	UPROPERTY(EditAnywhere, Category = "index")
	struct FBlackboardKeySelector Indexkey;

	UPROPERTY(EditAnywhere, Category = "NextWaypoint")
	struct FBlackboardKeySelector WaypointKey;

	
};
