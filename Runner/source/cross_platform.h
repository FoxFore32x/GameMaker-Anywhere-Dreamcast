#include <stdbool.h>

#ifdef __3DS__
    #include <3ds.h>
    #include <citro2d.h>
#endif

void scr_renderframe_3DS(C3D_RenderTarget* topscreen, float camerax, float cameray, float camera_width, float camera_height, size_t currentsprite_count, char* datajson, const char* my_currentroom);
void scr_drawroom_assets_3DS(size_t currentsprite_count, C2D_SpriteSheet Spritesheet, float sprite_x, float sprite_y, float sprite_scalex, float sprite_scaley, float sprite_rot, cJSON* root, cJSON*  spr);