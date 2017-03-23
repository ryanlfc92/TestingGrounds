// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "PatrolPointsComponent.h"




TArray<AActor*> UPatrolPointsComponent::GetPatrolPoints() const
{

	return PatrolPoints;
}