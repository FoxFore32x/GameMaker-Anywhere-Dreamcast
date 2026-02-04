#include <3ds.h>
#include "cJSON.h"

extern const char* CurrentRoom;
extern char* data_json;

u32 GetCurrentRoomBgColor_3DS(const char* json_text, const char* room_name);
int GetSpriteNumberByName(const cJSON* root, const char* sprite_name);
void InitCurrentRoom(const char* json_text);