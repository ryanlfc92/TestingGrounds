// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolPointsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolPointsComponent : public UActorComponent
{
	GENERATED_BODY()


public:

	TArray<AActor*> GetPatrolPoints() const;


private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol")
		TArray<AActor*> PatrolPoints;

	
};
