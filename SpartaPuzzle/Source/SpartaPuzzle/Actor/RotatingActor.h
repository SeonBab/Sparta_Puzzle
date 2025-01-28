// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "RotatingActor.generated.h"

/**
 * 
 */
UCLASS()
class SPARTAPUZZLE_API ARotatingActor : public ABaseActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	// ȸ�� �Լ�
	void Rotate(float DeltaTime);

private:
	// ȸ�� �ӵ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotate", meta = (AllowPrivateAccess = true))
	FRotator RotateSpeed;

	// �������� ���� �ٲ���
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	bool bIsRandomSpeed;
	// �������� ���� �ٲ� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FRotator MinRandomSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FRotator MaxRandomSpeed;
};
