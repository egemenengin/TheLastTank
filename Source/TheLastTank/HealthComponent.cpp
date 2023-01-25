// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TheLastTankGameMode.h"
// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	TheLastTankGameMode = Cast<ATheLastTankGameMode>(UGameplayStatics::GetGameMode(this));

	CurrentHealth = MaxHealth;
	
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageHandler);

}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::DamageHandler(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser)
{
	//UE_LOG(LogTemp, Display, TEXT("Damaged Actor: %s , Damage: %f , DamageCauser: %s "), *(DamagedActor->GetName()), Damage, *(DamageCauser->GetName()));
	
	if(Damage <= 0.f) return;

	CurrentHealth -= Damage;
	if(CurrentHealth <= 0)
	{
		if(TheLastTankGameMode)
		{
			TheLastTankGameMode->ActorDied(DamagedActor);
		}
	}
	//UE_LOG(LogTemp, Display, TEXT("Damaged Actor: %s , Current Health: %f  "), *(DamagedActor->GetName()), CurrentHealth);
}

