// Fill out your copyright notice in the Description page of Project Settings.


#include "Networking/RPGHttp_Items.h"
#include "Interfaces/IHttpResponse.h"
#include "Gameplay/Items/RPGItem.h"

RPGHttp_Items::RPGHttp_Items()
{
	Http = &FHttpModule::Get();
}

RPGHttp_Items::~RPGHttp_Items()
{
}

void RPGHttp_Items::HttpGetItemData(URPGItem* Item)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Http called"));

	// Create Request and bind OnComplete-Event
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();
	//Request->OnProcessRequestComplete().BindRaw(this, &RPGHttp_Items::OnResponseReceived);
	Request->OnProcessRequestComplete().BindRaw(this, &RPGHttp_Items::OnResponseReceived, Item);

	// localhost URL of expressjs webserver -> route to items
	Request->SetURL("http://localhost:3000/items/" + FString::FromInt(Item->GetItemID()));
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
	Request->SetHeader("Content-Type", TEXT("application/json"));

	Request->ProcessRequest();
}

void RPGHttp_Items::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, URPGItem* Item)
{
	if (Response->GetResponseCode() == EHttpResponseCodes::Ok)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Response received"));
		TSharedPtr<FJsonObject> JsonObject;
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, Response->GetContentAsString());
		TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

		if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, JsonObject->GetStringField("item_name"));

			//JsonObject->GetStringField("item_name");
			Item->ReloadItemData(
				JsonObject->GetStringField("item_name"),
				JsonObject->GetStringField("description"),
				JsonObject->GetStringField("image_path")
			);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, "JsonConversion failed");
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, "Failed Request - Code: " + Response->GetResponseCode());
	}
}
