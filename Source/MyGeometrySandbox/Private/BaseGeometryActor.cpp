// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();


	printStringTypes();
	printTypes();

}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGeometryActor::printTypes()
{
	UE_LOG(LogTemp, Display, TEXT("Hello UE!"));
	UE_LOG(LogTemp, Warning, TEXT("Hello UE!"));
	UE_LOG(LogTemp, Error, TEXT("Hello UE!"));

	int WeaponsNum = 5;
	int KillsNum = 7;
	float Health = 88.33f;
	bool IsDead = false;
	bool HasWeapon = true;

	UE_LOG(LogTemp, Display, TEXT("Weapons num: %d, kills num: %i"), WeaponsNum, KillsNum);
	UE_LOG(LogTemp, Display, TEXT("Health: %f"), Health);
	UE_LOG(LogTemp, Display, TEXT("Health: %.2f"), Health);
	UE_LOG(LogTemp, Display, TEXT("Is dead: %i"), IsDead);
	UE_LOG(LogTemp, Display, TEXT("Has weapon: %d"), static_cast<int>(HasWeapon));

}

void ABaseGeometryActor::printStringTypes()
{

	FString Name = "John Connor";
	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	int WeaponsNum = 5;
	float Health = 88.33333f;
	bool IsDead = false;

	FString WeaponsNumStr = "Weapons num = " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsDeadStr = "Is dead = " + FString(IsDead ? "true" : "false");

	FString Stat = FString::Printf(TEXT(" \n== All Stats == \n%s \n%s \n%s"), *WeaponsNumStr, *HealthStr, *IsDeadStr);
	UE_LOG(LogBaseGeometry, Display, TEXT("%s"), *Stat);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, Name);
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Emerald, Stat, true, FVector2D(1.5f, 1.5f));
};

