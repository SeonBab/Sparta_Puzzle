// Fill out your copyright notice in the Description page of Project Settings.


#include "HidingActor.h"

AHidingActor::AHidingActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHidingActor::BeginPlay()
{
	Super::BeginPlay();

	// ���� �� ��������� �ϴ� Ÿ�̸� ����
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AHidingActor::Hiding, ShowingTime, false);
}

void AHidingActor::Hiding()
{
	// Ÿ�̸� �ڵ鿡 �ִ� Ÿ�̸� ���� ����
	GetWorldTimerManager().ClearTimer(TimerHandle);

	if (!StaticMeshComp.IsNull())
	{
		// �����
		StaticMeshComp->SetHiddenInGame(true);
	}

	// ���̵��� �ϴ� Ÿ�̸� ����
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AHidingActor::Showing, HidingTime, false);
}

void AHidingActor::Showing()
{
	// Ÿ�̸� �ڵ鿡 �ִ� Ÿ�̸� ���� ����
	GetWorldTimerManager().ClearTimer(TimerHandle);

	if (!StaticMeshComp.IsNull())
	{
		// ��Ÿ��
		StaticMeshComp->SetHiddenInGame(false);
	}

	// ��������� �ϴ� Ÿ�̸� ����
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AHidingActor::Hiding, ShowingTime, false);
}
