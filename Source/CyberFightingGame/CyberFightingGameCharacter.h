// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CyberFightingGameCharacter.generated.h"

UCLASS(config=Game)
class ACyberFightingGameCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	void StartAttack1();
	void StartAttack2();
	void StartAttack3();
	void StartAttack4();

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Damage the player. 
	void TakeDamage(float _damageAmount);

	// Player has lightPunched
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacks")
	bool lPunched;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacks")
	bool hPunched;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacks")
	bool lKick;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacks")
	bool hKick;

	// The Amount of health a character has.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float playerHealth;
	 
	// End of APawn interface


public:
	ACyberFightingGameCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
