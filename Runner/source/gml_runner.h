#include "cJSON.h"
#include <stdio.h>
#include <stddef.h>

extern size_t SpriteCount;
extern int sprite_object_id[MAX_SPRITES];

#pragma once //This is a header guard, it prevents the file from being included multiple times which can cause errors

typedef struct var {
    const char* name;
    void* value;
    struct var* next;
} var;


bool runner_sprite_is_object(int index);
void GML_SetRoot(const cJSON* root);
void RunGML_create(const char* code, int defIndex);
void RunGML_step(const char* code, int defIndex);
void RunGML(void);

