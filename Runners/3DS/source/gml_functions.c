#include <citro2d.h>
#include "gml_functions.h"
#include <stdio.h>

#pragma region //Input functions
//check gamepad button is held
bool gamepad_button_check_pressed(u32 ButtonPressed) {
	if (g_keysDown & ButtonPressed)
		return true;
	else
		return false;
}

//check gamepad button is pressed
bool gamepad_button_check(u32 ButtonPressed) {
	if (g_keysHeld & ButtonPressed)
		return true;
	else
		return false;
}

//check gamepad button is released
bool gamepad_button_check_released(u32 ButtonPressed) {
	if (g_keysUp & ButtonPressed)
		return true;
	else
		return false;
}
#pragma endregion

#pragma region //Debug functions

//quick print to the console
void show_debug_message(const char* Printor)
{
	printf("%s\n", Printor);
}

#pragma endregion

#pragma region //Drawing functions
void draw_sprite(int spritenumber, C2D_SpriteSheet sheet, float x, float y) {
	if (SpriteCount >= MAX_SPRITES)
		return;

	Sprite* sprite = &sprites[SpriteCount];
	C2D_SpriteFromSheet(&sprite->spr, sheet, spritenumber);
	C2D_SpriteSetPos(&sprite->spr, x, y);

	SpriteCount++;
}
#pragma endregion
