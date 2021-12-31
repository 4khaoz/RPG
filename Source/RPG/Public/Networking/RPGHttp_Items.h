// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"

/**
 * 
 */
class RPG_API RPGHttp_Items
{
public:
	RPGHttp_Items();
	~RPGHttp_Items();

	void TestHttpCall(int item_id);

	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

protected:
	FHttpModule* Http;
};
