#include "MC.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"

#include "Camera/CameraComponent.h"

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
    OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
    OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
    OurVisibleComponent->SetupAttachment(RootComponent);


}

void AMC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind input axes for movement
    PlayerInputComponent->BindAxis("MoveForward", this, &AMC::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AMC::MoveRight);
}

void AMC::MoveForward(float Value)
{
    // Calculate movement direction
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    CurrentVelocity = Direction * Value * MoveSpeed;
}

void AMC::MoveRight(float Value)
{
    // Calculate movement direction
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    CurrentVelocity = Direction * Value * MoveSpeed;
}

void AMC::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Apply movement
    FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
    SetActorLocation(NewLocation);
}