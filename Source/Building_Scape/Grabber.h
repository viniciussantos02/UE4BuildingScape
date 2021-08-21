// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/PlayerController.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_SCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGrabber();	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	APlayerController* PlayerController;
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	FVector LineTraceEnd;
	FHitResult Hit;

	float ReachArm = 200.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	void GrabPressed();
	void GrabReleased();
	void CheckPhysicsHandle();
	void SetupInputBinds();
	FHitResult GetFirstPhysicsBodyInReach();
	void GetLineTraceEnd();
};