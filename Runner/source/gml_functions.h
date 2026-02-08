#pragma once

#ifdef __3DS__
    #include <3ds.h>
    #include <citro2d.h>

    //inputs
    #define gp_start KEY_START
    #define gp_select KEY_SELECT
    #define gp_face1 KEY_B
    #define gp_face2 KEY_A
    #define gp_face3 KEY_Y
    #define gp_face4 KEY_X
    #define gp_padl KEY_DLEFT
    #define gp_padr KEY_DRIGHT
    #define gp_padu KEY_DUP
    #define gp_padd KEY_DDOWN
#endif

#ifdef __DC__
    #include <kos.h>
    #include <raylib.h>

    //inputs
    #define gp_start GAMEPAD_BUTTON_MIDDLE_RIGHT
    #define gp_select GAMEPAD_BUTTON_MIDDLE_LEFT
    #define gp_face1 GAMEPAD_BUTTON_RIGHT_FACE_DOWN
    #define gp_face2 GAMEPAD_BUTTON_RIGHT_FACE_RIGHT
    #define gp_face3 GAMEPAD_BUTTON_RIGHT_FACE_LEFT
    #define gp_face4 GAMEPAD_BUTTON_RIGHT_FACE_UP
    #define gp_padl GAMEPAD_BUTTON_LEFT_FACE_LEFT
    #define gp_padr GAMEPAD_BUTTON_LEFT_FACE_RIGHT
    #define gp_padu GAMEPAD_BUTTON_LEFT_FACE_UP
    #define gp_padd GAMEPAD_BUTTON_LEFT_FACE_DOWN
#endif

#include <stdbool.h>
#include <stddef.h>

//max sprites that can be drawn at a time
#define MAX_SPRITES 1000


extern u32 g_keysDown;
extern u32 g_keysHeld;
extern u32 g_keysUp;

typedef struct
{
    #ifdef __3DS__
    C2D_Sprite spr;
    #elif __DC__
    Texture2D texture;
    #endif
} Sprite;

/*struct Sprite
{
    C2D_Sprite spr;
    Sprite* next;
}*/

extern Sprite sprites[MAX_SPRITES];
extern size_t SpriteCount;




//input
#ifdef __3DS__
bool gamepad_button_check_pressed(u32 Button);
bool gamepad_button_check(u32 Button);
bool gamepad_button_check_released(u32 Button);
#elif __DC__
bool gamepad_button_check_pressed(int Button);
bool gamepad_button_check(int Button);
bool gamepad_button_check_released(int Button);
#endif
bool runner_sprite_is_object(int index);

//debugging
void show_debug_message(const char* Printor);

//drawing
void draw_sprite(int spritenumber, C2D_SpriteSheet sheet, float x, float y);