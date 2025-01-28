// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseActor.h"

ABaseActor::ABaseActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// �⺻ ������Ʈ ����
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}

void ABaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}