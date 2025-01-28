// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "MovingActor.generated.h"

UCLASS()
class SPARTAPUZZLE_API AMovingActor : public ABaseActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
private:
	// �̵� �Լ�
	void Move(float DeltaTime);

private:
	// ���� ��ġ
	FVector StartLocation;
	// �̵��� ����
	FVector Direction;

	// �̵� �ӵ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MoveSpeed;
	// �ִ� �̵� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MaxMoveRange;

	// �������� ���� �ٲ���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	bool bIsRandomSpeed;
	// �������� ���� �ٲ� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MinRandomSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MaxRandomSpeed;

	// �������� ���� �ٲ���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	bool bIsRandomRange;
	// �������� ���� �ٲ� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MinRandomMoveRange;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MaxRandomMoveRange;
};
