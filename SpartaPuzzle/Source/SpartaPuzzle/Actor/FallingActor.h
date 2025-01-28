// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "FallingActor.generated.h"

class UBoxComponent;

UCLASS()
class SPARTAPUZZLE_API AFallingActor : public ABaseActor
{
	GENERATED_BODY()

public:
	AFallingActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	void ChageMaterial();

	void Falling();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision", meta = (AllowPrivateAccess = true))
	TObjectPtr<UBoxComponent> BoxCoollisionComp;

	// Ÿ�̸� �ڵ�
	FTimerHandle MaterialTimerHandle;
	FTimerHandle FallingTimerHandle;

	// �������µ� �ʿ��� �ð�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fall", meta = (AllowPrivateAccess = true))
	float FallingTime;

	// �������� �� ���� �� ��Ƽ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fall", meta = (AllowPrivateAccess = true))
	TObjectPtr<UMaterial> ChangeMaterial;
};
