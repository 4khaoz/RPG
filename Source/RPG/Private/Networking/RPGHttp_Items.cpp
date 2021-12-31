// Fill out your copyright notice in the Description page of Project Settings.


#include "Networking/RPGHttp_Items.h"
#include "Interfaces/IHttpResponse.h"

RPGHttp_Items::RPGHttp_Items()
{
	Http = &FHttpModule::Get();
}

RPGHttp_Items::~RPGHttp_Items()
{
}

void RPGHttp_Items::TestHttpCall(int item_id)
{
	// Create Request and bind OnComplete-Event
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindRaw(this, &RPGHttp_Items::OnResponseReceived);

	// localhost URL of expressjs webserver -> route to items
	Request->SetURL("http://localhost:3000/items/" + FString::FromInt(item_id));
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent"));
	Request->SetHeader("Content-Type", TEXT("application/json"));

	Request->ProcessRequest();
}

void RPGHttp_Items::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (Response->GetResponseCode() == EHttpResponseCodes::Ok)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, Response->GetContentAsString());
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, "Failed Request - Code: " + Response->GetResponseCode());
	}
}
