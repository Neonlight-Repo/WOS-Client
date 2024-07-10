// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/LoginUI.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "generated/account/ClientPacketHandler.gen.hpp"
#include "Managers/Manager.h"
#include "Managers/Network.h"
#include "Managers/UISystem.h"

void ULoginUI::NativeConstruct()
{
	Super::NativeConstruct();

	BLogin->OnClicked.AddDynamic(this, &ULoginUI::OnClickLogin);
	BJoin->OnClicked.AddDynamic(this, &ULoginUI::OnClickJoin);
}

void ULoginUI::OnClickLogin()
{
	gen::account::LoginReq req;
	req.nickname = ID->GetText().ToString();
	req.password = FMD5::HashAnsiString(*PW->GetText().ToString());
	UManager::Net()->Send(ServerType::Account, &req);
}

void ULoginUI::SetBlank() {
	ID->SetText(FText::FromString(TEXT("")));
	PW->SetText(FText::FromString(TEXT("")));
}

FText ULoginUI::GetID() const {
	return ID->GetText();
}

void ULoginUI::SuccessLogin() const
{
	UManager::UI(GetWorld())->ShowWidget(WidgetType::InGame);
	UManager::UI(GetWorld())->HideWidget(WidgetType::Login);
}

void ULoginUI::OnClickJoin()
{
	UManager::UI(GetWorld())->ShowWidget(WidgetType::Join);
}