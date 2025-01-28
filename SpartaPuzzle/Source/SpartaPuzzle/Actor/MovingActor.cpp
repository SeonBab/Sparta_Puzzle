// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	Direction = FVector::One();

	if (bIsRandomSpeed)
	{
		MoveSpeed.X = FMath::RandRange(MinRandomSpeed.X, MaxRandomSpeed.X);
		MoveSpeed.Y = FMath::RandRange(MinRandomSpeed.Y, MaxRandomSpeed.Y);
		MoveSpeed.Z = FMath::RandRange(MinRandomSpeed.Z, MaxRandomSpeed.Z);
	}

	if (bIsRandomRange)
	{
		MaxMoveRange.X = FMath::RandRange(MinRandomMoveRange.X, MaxRandomMoveRange.X);
		MaxMoveRange.Y = FMath::RandRange(MinRandomMoveRange.Y, MaxRandomMoveRange.Y);
		MaxMoveRange.Z = FMath::RandRange(MinRandomMoveRange.Z, MaxRandomMoveRange.Z);
	}
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
}

void AMovingActor::Move(float DeltaTime)
{
	// ���� ��ġ ������� �ð��� ����� �̵��� ��ġ�� ����
	FVector NewLocation = GetActorLocation();
	NewLocation += MoveSpeed * DeltaTime * Direction;

	// �ִ� �̵� ������ ����ٸ� �̵��� ������ �ݴ�� ����
	if (NewLocation.X > StartLocation.X + MaxMoveRange.X || NewLocation.X < StartLocation.X - MaxMoveRange.X)
	{
		// ���ο� ��ġ�� �ִ� ������ ���� �ʵ��� �� �缳��
		NewLocation.X = StartLocation.X + MaxMoveRange.X * Direction.X;

		Direction.X *= -1;
	}
	if (NewLocation.Y > StartLocation.Y + MaxMoveRange.Y || NewLocation.Y < StartLocation.Y - MaxMoveRange.Y)
	{
		// ���ο� ��ġ�� �ִ� ������ ���� �ʵ��� �� �缳��
		NewLocation.Y = StartLocation.Y + MaxMoveRange.Y * Direction.Y;

		Direction.Y *= -1;
	}
	if (NewLocation.Z > StartLocation.Z + MaxMoveRange.Z || NewLocation.Z < StartLocation.Z - MaxMoveRange.Z)
	{
		// ���ο� ��ġ�� �ִ� ������ ���� �ʵ��� �� �缳��
		NewLocation.Z = StartLocation.Z + MaxMoveRange.Z * Direction.Z;

		Direction.Z *= -1;
	}

	// ��ġ �� ����
	SetActorLocation(NewLocation);
}
