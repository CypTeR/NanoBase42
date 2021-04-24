
#pragma once
#include "stdafx.h"



bool invisible = false;
void Invisible()
{
	if (invisible)
	{

		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false,0);
	}
	else
	{ 
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true,0);
	}
}
bool superjump = false;
void SuperJump()
{
	if (superjump)
	{

		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_PED_ID());
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
	}
	else
	{
		NULL;
	}
}
bool neverwanted = false;
void NeverWanted()
{
	Entity player = PLAYER::PLAYER_PED_ID();
	if (neverwanted)
	{
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_MAX_WANTED_LEVEL(0);
		PLAYER::SET_POLICE_IGNORE_PLAYER(player, true);
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, true);
		PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, false);

	}
	else
	{
		PLAYER::SET_MAX_WANTED_LEVEL(5);
		PLAYER::SET_POLICE_IGNORE_PLAYER(player, false);
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, false);
		PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, true);
		PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, false);
	}
}

void main() 
{
	notifyMap("~r~CypTeR Yuklendi!");
	while (true) 
	{
		SuperJump();
		Invisible();
		NeverWanted();
		Menu::Checks::Controlls();
		godmode(GODMODE);

		switch (Menu::Settings::currentMenu) {

		case mainmenu:
		{
			Menu::Title("CypTeR Menu");
			Menu::MenuOption("~g~Kisisel  ~b~>", sub);
			Menu::MenuOption("~c~Cevrimici (Yakinda) ~b~>", bos); //, plist);
			Menu::MenuOption("~c~Silah (Yakinda) ~b~>", bos);
			Menu::MenuOption("~c~Olustur (Yakinda) ~b~>", bos);
			Menu::MenuOption("~c~Scrpitler (Yakinda) ~b~>", bos);
			Menu::MenuOption("~c~Isinlanma (Yakinda) ~b~>", bos);
			Menu::MenuOption("~c~Dunya (Yakinda)  ~b~>", bos);
			Menu::MenuOption("~c~Cesitli (Yakinda)  ~b~>", bos);
			Menu::MenuOption("~f~Anti Ban ~b~>", bos);
			Menu::MenuOption("~o~Ayarlar ~b~>", settings);
			Menu::MenuOption("~r~Hakkimizda ~b~>", Credits);
		}
		break;

		case sub:
		{
			Menu::Title("Kisisel");
			Menu::Toggle("Allah Modu", GODMODE);
			Menu::Toggle("Polis YOK!", neverwanted);
			Menu::Toggle("Gorunmez Ol", invisible);
			Menu::Toggle("Yuksek Ziplama", superjump);
		}
		break;
		case bos:
		{
			notifyMap("~r~YAKINDA DEDIK YA!");
			
		}
		break;
		/*case plist:
		{
			Menu::Title("Kullanicilar");
			for (int i; i <= 32; i++) {
				if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(i)) {
					Menu::PlayerOption(i);
				}
			}
		}
		break;
		case pmenu:
		{
			Menu::Title(PLAYER::GET_PLAYER_NAME(selectedPlayer));
			Menu::Break("Calisiyor!");
		}
		break;*/
		case settings:
		{	
			Menu::Title("Ayarlar");
			Menu::MenuOption("Renkler ~b~>", settingstheme);
			if (Menu::Int("Kaydirici delayi", Menu::Settings::keyPressDelay2, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::keyPressDelay2 = NumberKeyboard();
				}
			}
			if (Menu::Int("Int Delay", Menu::Settings::keyPressDelay3, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::keyPressDelay3 = NumberKeyboard();
				}
			}
			Menu::Option("~HUD_COLOUR_GOLD~Social Club Hesabi:");
			Menu::Option(PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()));
			Menu::MenuOption("~r~GTAdan Cik?", exitgta);
			
		}
		break;
		case exitgta:
		{
			Menu::Title("GTAdan Cik?");
			if (Menu::Option("EVET!")) exit(0);
		}
		break;
		case settingstheme:
		{
			Menu::Title("Renkler");
			Menu::MenuOption("Theme Loader ~b~>", themeloader);
			Menu::MenuOption("Title Background ~b~>", settingstitlerect);
			Menu::MenuOption("Selection Box ~b~>", settingsscroller);
			Menu::MenuOption("Option Text ~b~>", settingsoptiontext);
			if (Menu::Option("MenuX plus")) {
				if (Menu::Settings::menuX < 0.81f) Menu::Settings::menuX += 0.01f;
			}
			if (Menu::Option("MenuX minus")) {
				if (Menu::Settings::menuX > 0.17f) Menu::Settings::menuX -= 0.01f;
			}
		}
		break;
		case Credits:
		{
			Menu::Title("Hakkimizda");
			Menu::Option("Yapimci : ~r~CypTeR");
			Menu::Option("Proje : ~HUD_COLOUR_GOLD~CypTeR");
			Menu::Option("Amac : Acik Kaynak Turkce Hile");
			Menu::Option("Versiyon : BETA 0.1.1");
		}
		break;
		case themeloader:
		{
			Menu::Title("Theme Colors");
			if (Menu::Option("Red Theme")) {
				Menu::Settings::titleRect = { 100, 0, 0, 255 };
				Menu::Settings::scroller = { 100, 0, 0, 255 };
			}
			if (Menu::Option("Blue Theme")) {
				Menu::Settings::titleRect = { 0, 0, 200, 255 };
				Menu::Settings::scroller = { 0, 0, 200, 255 };
			}
			if (Menu::Option("Green Theme")) {
				Menu::Settings::titleRect = { 0, 180, 0, 255 };
				Menu::Settings::scroller = { 0, 0, 180, 255 };
			}
			if (Menu::Option("Load Default Theme")) {
				Menu::Settings::titleText = { 255, 255, 255, 255, 7 };
				Menu::Settings::titleRect = { 100, 0, 0, 255 };
				Menu::Settings::scroller = { 100, 0, 0, 255 };
				Menu::Settings::optionText = { 255, 255, 255, 255, 0 };
				Menu::Settings::optionRect = { 0, 0, 0, 110 };
			}
		}
		break;
		case settingstitlerect:
		{
			Menu::Title("Title Rect");
			if (Menu::Int("Red", Menu::Settings::titleRect.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::titleRect.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::titleRect.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::titleRect.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.a = NumberKeyboard();
				}
			}
		}
		break;
		case settingsoptiontext:
		{
			Menu::Title("Option Text");
			if (Menu::Int("Red", Menu::Settings::optionText.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::optionText.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::optionText.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::optionText.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.a = NumberKeyboard();
				}
			}
			Menu::MenuOption("Font ~b~>", font);
		}
		break;
		case font:
		{
			Menu::Title("Font");
			if (Menu::Option("Chalet London")) { Menu::Settings::optionText.f = 0; }
			if (Menu::Option("House Script")) { Menu::Settings::optionText.f = 1; }
			if (Menu::Option("Monospace")) { Menu::Settings::optionText.f = 2; }
			if (Menu::Option("Wing Dings")) { Menu::Settings::optionText.f = 3; }
			if (Menu::Option("Chalet Comprime Cologne")) { Menu::Settings::optionText.f = 4; }
			if (Menu::Option("Pricedown")) { Menu::Settings::optionText.f = 7; }
		}
		break;
		case settingsscroller:
		{
			Menu::Title("Scroller");
			if (Menu::Int("Red", Menu::Settings::scroller.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::scroller.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::scroller.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::scroller.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.a = NumberKeyboard();
				}
			}
		}
		break;

		}
		Menu::End();
		WAIT(0);
	}
}

void ScriptMain() {
	srand(GetTickCount());

	main();
}