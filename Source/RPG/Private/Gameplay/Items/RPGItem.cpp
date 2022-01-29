// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Items/RPGItem.h"

void URPGItem::ReloadItemData(FString name, FString description, FString imagepath)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("ReloadItemData called"));
	ItemName = FText::FromString(name);
	ItemDescription = FText::FromString(description);
	ItemImage = LoadObject<UTexture2D>(NULL, *imagepath, NULL, LOAD_None, NULL);
}

void URPGItem::LoadItemData()
{
	RPGHttp_Items* http = new RPGHttp_Items();
	//http->TestHttpCall(id);
	http->HttpGetItemData(this);


	//ItemImage = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/Assets/Textures/Testimage.Testimage'"), NULL, LOAD_None, NULL);
}
