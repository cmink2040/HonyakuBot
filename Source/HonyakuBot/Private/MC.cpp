#include "MC.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"


#include "EnhancedInputSubsystems.h"

AMC::AMC()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Set this pawn to be controlled by the lowest-numbered player
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    // Create a dummy root component we can attach things to.
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    // Create a camera and a visible object
    UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
    OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
    // Attach our camera and visible object to our root component. Offset and rotate the camera.
    OurCamera->SetupAttachment(RootComponent);
    OurCamera->SetRelativeLocation(FVector(-800.0f, 0.0f, 400.0f));
    OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
    OurVisibleComponent->SetupAttachment(RootComponent);


}

void AMC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    auto playerController = Cast<APlayerController>(GetController());

    auto eiSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());
    //Add the input mapping context
    eiSubsystem->AddMappingContext(inputMappingContext, 0);
    UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    enhancedInputComponent->BindAction(inputMove, ETriggerEvent::Triggered , this, &AMC::InputMove);
}
void AMC::InputMove(const FInputActionValue& Value)
{
    UE_LOG(LogTemp, Display, TEXT("Float Key: %f"), Value.Get<FVector2d>().X);

        const FVector2d moveVec = Value.Get<FVector2d>();
        const FRotator rotate(0.0f, Controller -> GetControlRotation().Yaw, 0.0f);

        const FVector dirx = rotate.RotateVector(FVector::RightVector);

        const FVector diry = rotate.RotateVector(FVector::RightVector);



        if (moveVec.X > 0.05f || moveVec.X < -0.05f)
        {
           // AddMovementInput(dir, moveVec.X);
        }

        if (moveVec.Y > 0.05f || moveVec.Y < -0.05f)
        {
         //  AddMovementInput(dir, moveVec.Y);
        }

        
        // Move forward logic
        // Example: Move the pawn forward
       // const FVector ForwardVector = GetActorForwardVector();
        //AddMovementInput(ForwardVector, 1.0f);

    CurrentVelocityX = dirx  * MoveSpeed * -1;
    CurrentVelocityY = diry  * MoveSpeed * -1;


    
}
void AMC::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Apply movement
    const FVector NewLocation = GetActorLocation() + (CurrentVelocityX * DeltaTime);
    SetActorLocation(NewLocation);
    SetActorLocation( GetActorLocation() + (CurrentVelocityY * DeltaTime) );

}