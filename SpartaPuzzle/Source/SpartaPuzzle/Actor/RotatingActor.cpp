// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingActor.h"

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();

	if (bIsRandomSpeed)
	{
		RotateSpeed.Pitch = FMath::RandRange(MinRandomSpeed.Pitch, MaxRandomSpeed.Pitch);
		RotateSpeed.Yaw = FMath::RandRange(MinRandomSpeed.Yaw, MaxRandomSpeed.Yaw);
		RotateSpeed.Roll = FMath::RandRange(MinRandomSpeed.Roll, MaxRandomSpeed.Roll);
	}
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotate(DeltaTime);
}

void ARotatingActor::Rotate(float DeltaTime)
{
	FRotator NewRotate;

	// �ð��� ����� ȸ�� ���� ����
	NewRotate = RotateSpeed * DeltaTime;

	// ���� ȸ�� ���� ����
	AddActorLocalRotation(NewRotate);
}
