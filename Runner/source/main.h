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


u32 GetCurrentRoomBgColor_3DS(const char* json_text, const char* room_name);
int GetSpriteNumberByName(const cJSON* root, const char* sprite_name);