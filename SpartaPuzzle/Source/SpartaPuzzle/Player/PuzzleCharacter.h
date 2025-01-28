// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PuzzleCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

struct FInputActionValue;

UCLASS()
class SPARTAPUZZLE_API APuzzleCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APuzzleCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// �Է� ���ε�
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// �Է½� ȣ�� �� �Լ�
	// ĳ���� �̵�
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	// ���콺�� ���� ���� ȸ��
	UFUNCTION()
	void Look(const FInputActionValue& Value);
	// ĳ���� ����
	UFUNCTION()
	void StartJump(const FInputActionValue& Value);
	UFUNCTION()
	void StopJump(const FInputActionValue& Value);

private:
	// ī�޶� ���� ������Ʈ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> CameraComp;

	// �̵� �⺻ �ӵ�
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = true))
	float NormalMoveSpeed;
};
