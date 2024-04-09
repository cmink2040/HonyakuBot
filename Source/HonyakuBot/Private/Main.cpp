#include "Main.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"


#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"

AMain::AMain()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Set this pawn to be controlled by the lowest-numbered player
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    // Create a dummy root component we can attach things to.
    // Create a camera and a visible object
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    VisibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleMesh"));
    // Attach our camera and visible object to our root component. Offset and rotate the camera.

    CameraComponent->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
    VisibleMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);



}

void AMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    auto playerController = Cast<APlayerController>(GetController());

    auto eiSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());
    //Add the input mapping context
    eiSubsystem->AddMappingContext(inputMappingContext, 0);
    UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    enhancedInputComponent->BindAction(inputMove, ETriggerEvent::Triggered , this, &AMain::InputMove);

    enhancedInputComponent->BindAction(Look, ETriggerEvent::Triggered , this, &AMain::CamLook);

}
void AMain::CamLook(const FInputActionValue& Value)
{
    
}

void AMain::InputMove(const FInputActionValue& Value)
{
    UE_LOG(LogTemp, Display, TEXT("Float Key: %f %f"), Value.Get<FVector2d>().X, Value.Get<FVector2d>().Y);

    const FVector2d moveVec = Value.Get<FVector2d>();

        const FVector DirectionX = FRotator(0.0f, Controller -> GetControlRotation().Yaw, Controller -> GetControlRotation().Roll).RotateVector(FVector::RightVector);
        AddMovementInput(DirectionX, moveVec.X);

    
        const FVector DirectionY = FRotator(0.0f, Controller -> GetControlRotation().Yaw, 0.0f).RotateVector(FVector::ForwardVector);
        AddMovementInput(DirectionY, moveVec.Y);

        this->GetCharacterMovement()->MaxWalkSpeed = 800.f;


        
        // Move forward logic
        // Example: Move the pawn forward
       // const FVector ForwardVector = GetActorForwardVector();
        //AddMovementInput(ForwardVector, 1.0f);



    
}
void AMain::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Apply movement

}