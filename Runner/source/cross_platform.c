#include "main.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cJSON.h"
#include <math.h>
#include "gml_functions.h"
#include "gml_runner.h"
#include "gml_runner.h"
#include "shortcut_functions.h"
#include "cross_platform.h"
#include <stdbool.h>

#ifdef __3DS__
    #include <3ds.h>
    #include <citro2d.h>
#endif



void scr_renderframe_3DS(C3D_RenderTarget* topscreen, float camerax, float cameray, float camera_width, float camera_height, size_t currentsprite_count, char* datajson, const char* my_currentroom){
    //Start the frame
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

    //top
    C2D_TargetClear(topscreen, GetCurrentRoomBgColor_3DS(datajson, my_currentroom));
    C2D_SceneBegin(topscreen);

    //camera
    C2D_ViewReset();
    C2D_ViewTranslate(-camerax, -cameray);
    C2D_ViewScale(400 / camera_width, 240 / camera_height);

    //draw sprites
    for (size_t i = 0; i < currentsprite_count; i++)
        C2D_DrawSprite(&sprites[i].spr);

    //finish view
    C2D_ViewReset();
    //gui drawing goes here...


    //end frame
    C3D_FrameEnd(0);
}

void scr_drawroom_assets_3DS(size_t currentsprite_count, C2D_SpriteSheet Spritesheet, float sprite_x, float sprite_y, float sprite_scalex, float sprite_scaley, float sprite_rot, cJSON* root, cJSON* spr){
    Sprite* sp = &sprites[currentsprite_count];
    C2D_SpriteFromSheet(&sp->spr, Spritesheet, GetSpriteNumberByName(root, spr->valuestring));
    C2D_SpriteSetPos(&sp->spr, sprite_x, sprite_y);
    C2D_SpriteSetScale(&sp->spr, sprite_scalex, sprite_scaley);
    C2D_SpriteSetRotation(&sp->spr, sprite_rot);
}
