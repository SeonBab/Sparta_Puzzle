// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "HidingActor.generated.h"

/**
 * 
 */
UCLASS()
class SPARTAPUZZLE_API AHidingActor : public ABaseActor
{
	GENERATED_BODY()
	
public:
	AHidingActor();

protected:
	virtual void BeginPlay();

private:
	// ��������� �ϴ� �Լ�
	void Hiding();

	// ��Ÿ������ �ϴ� �Լ�
	void Showing();

private:
	// Ÿ�̸� �ڵ�
	FTimerHandle TimerHandle;

	// ������µ� �ʿ��� �ð�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotate", meta = (AllowPrivateAccess = true))
	float HidingTime;
	// ��Ÿ���µ� �ʿ��� �ð�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotate", meta = (AllowPrivateAccess = true))
	float ShowingTime;
};
