// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"

// Lesson 2 ((FString)
#include "Engine/engine.h"

// Lesson 2 ((FString)
DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();
		
	//printTransform();
	//printStringTypes();
	//printTypes();

}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// z = z0 + amplitude * sin(freq * t);
	FVector CurrentLocation = GetActorLocation();
	float time = GetWorld()->GetTimeSeconds();
	CurrentLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * time);

	SetActorLocation(CurrentLocation);

}

// Lesson 1 (UE_LOG)
void ABaseGeometryActor::printTypes() const
{
//	UE_LOG(LogTemp, Display, TEXT("Hello UE!"));
//	UE_LOG(LogTemp, Warning, TEXT("Hello UE!"));
//	UE_LOG(LogTemp, Error, TEXT("Hello UE!"));


	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Weapons num: %d, kills num: %i"), WeaponsNum, KillsNum);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Health: %f"), Health);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Is dead: %i"), IsDead);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Has weapon: %d"), static_cast<int>(HasWeapon));

}

// Lesson 2 ((FString)
void ABaseGeometryActor::printStringTypes() const
{

	FString Name = "John Connor";
	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	FString WeaponsNumStr = "Weapons num = " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsDeadStr = "Is dead = " + FString(IsDead ? "true" : "false");

	FString Stat = FString::Printf(TEXT(" \n== All Stats == \n%s \n%s \n%s"), *WeaponsNumStr, *HealthStr, *IsDeadStr);
	UE_LOG(LogBaseGeometry, Display, TEXT("%s"), *Stat);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, Name);
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Emerald, Stat, true, FVector2D(1.5f, 1.5f));
}

// Lesson 3 (Компоненты. Тип FTransform)
void ABaseGeometryActor::printTransform() const
{
	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Transform %s"), *Transform.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Location %s"), *Location.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Rotation %s"), *Rotation.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Scale %s"), *Scale.ToString());

	UE_LOG(LogBaseGeometry, Error, TEXT("Human transform %s"), *Transform.ToHumanReadableString());
}