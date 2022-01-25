// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Items/RPGItem.h"

void URPGItem::LoadItemData(int id)
{
	RPGHttp_Items* http = new RPGHttp_Items();
	http->TestHttpCall(id);
	


	ItemImage = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/Assets/Textures/Testimage.Testimage'"), NULL, LOAD_None, NULL);
}
