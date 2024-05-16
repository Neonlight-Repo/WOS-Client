// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameActor/PlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Rpc.h"
#include "LocalPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WOS_API ALocalPlayerCharacter : public APlayerCharacter
{
	GENERATED_BODY()
private:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override;
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaTime)override;

	void MoveHandler(const FInputActionValue& Value);
	void JumpHandler();
	void AttackHandler();
	RPC_FUNCTION(Test)
	void Test(bool bIsMine);

	UPROPERTY(EditAnywhere, Category = Input)
		UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, Category = Input)
		UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, Category = Input)
		UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, Category = Input)
		UInputAction* AttackAction;
	UPROPERTY(EditAnywhere, Category = Move)
		float MoveSpeed;
private:
	static constexpr float sendPositionInterval = 0.2f;

	float LastMoveInput;
	float LastSendPositionTime;
	FVector SpriteOriginScale;

	void SendMovePacket(float X, float Y);
};
