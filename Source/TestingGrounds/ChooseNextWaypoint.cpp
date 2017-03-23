// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrolPointsComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	
	//Get PatrolPointsCPP
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	
	auto PatrolPointsComponent = ControlledPawn->FindComponentByClass<UPatrolPointsComponent>();
	if (!ensure(PatrolPointsComponent)) { return EBTNodeResult::Failed; }

	auto PatrolPoints = PatrolPointsComponent->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("There are no Patrol Points"));
		return EBTNodeResult::Failed;
	}
	
	//Set NextWaypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(Indexkey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
	
	//cycle index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(Indexkey.SelectedKeyName, NextIndex);
	
	
	
	return EBTNodeResult::Succeeded;
}
