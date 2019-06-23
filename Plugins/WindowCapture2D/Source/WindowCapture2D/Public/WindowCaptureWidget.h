// Copyright 2019 ayumax. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "blueprint/UserWidget.h"
#include "CaptureMachineProperties.h"
#include "CaptureMachine.h"
#include "WindowCaptureWidget.generated.h"

class UInputTransferToWindow;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWindowCaptureWidgetChangeTexture, UTexture2D*, NewTexture);

UCLASS(BlueprintType, Blueprintable)
class WINDOWCAPTURE2D_API UWindowCaptureWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:	
	UWindowCaptureWidget(const FObjectInitializer& ObjectInitializer);

protected:
	UFUNCTION(BlueprintCallable, Category = WindowCapture2D)
	UTexture2D* Start();

	UFUNCTION()
	void OnChangeTexture(UTexture2D* NewTexture);

public:	
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WindowCapture2D)
	FCaptureMachineProperties Properties;

	UPROPERTY(BlueprintReadOnly, Category = SceneCapture)
	class UTexture2D* TextureTarget;

	UPROPERTY(BlueprintAssignable, Category = SceneCapture)
	FWindowCaptureWidgetChangeTexture ChangeTexture;

protected:
	UPROPERTY(Transient)
	UCaptureMachine* CaptureMachine = nullptr;

	UPROPERTY(Transient)
	UInputTransferToWindow* InputTransfer = nullptr;

protected:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

};
