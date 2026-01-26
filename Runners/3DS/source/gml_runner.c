#include <citro2d.h>
#include "gml_functions.h"
#include <stdio.h>
#include "cJSON.h"
#include <string.h>
#include "gml_runner.h"
#include <stdlib.h>
#include <stdbool.h>

static const cJSON* g_root = NULL;

//carry over the root from the main.c (probably better way i could've done this...)
void GML_SetRoot(const cJSON* root)
{
	g_root = root;
}

//return next object
static int runner_next_object_index(int* cursor, int defIndex)
{
    for (int tries = 0; tries < (int)SpriteCount; tries++)
    {
        if (*cursor >= (int)SpriteCount)
            *cursor = 0;

        int object = *cursor;
        (*cursor)++;

        if (runner_sprite_is_object(object) && sprite_object_id[object] == defIndex)
            return object;
    }

    return -1;
}
//applys the x and y of the objects
static void runner_apply_xy_code(int object_index, const char* code)
{
	float current_x = sprites[object_index].spr.params.pos.x;
	float current_y = sprites[object_index].spr.params.pos.y;
	const char* cursor = code;

	while (cursor && *cursor)
	{
		//check if this is a x or y statment
		char axis = *cursor;
		if (axis != 'x' && axis != 'y')
		{
			while (*cursor && *cursor != ';') cursor++;
			if (*cursor == ';')
				cursor++;

			continue;
		}
		cursor++;

		//skip empty space
		while (*cursor == ' ' || *cursor == '\t' || *cursor == '\r' || *cursor == '\n')
			cursor++;


		//check if doing addition, subtraction, set to, ect
		bool to_add = false;
		bool to_subtract = false;
		bool to_multi = false;
		
		if (*cursor == '+')
		{
			cursor++;
			to_add = true;
			cursor++;
		}
		else if (*cursor == '-')
		{
			cursor++;
			to_subtract = true;
			cursor++;
		}		
		else if (*cursor == '*')
		{
			cursor++;
			to_multi = true;
			cursor++;
		}
		else if (*cursor == '=')
		{
			cursor++;
		}

		//parse number
		char* endptr = NULL;
		float value = (float)strtod(cursor, &endptr);

		if (endptr != cursor)
		{
			if (axis == 'x'){
				if (to_add)
					current_x += value;
				else if (to_subtract)
					current_x -= value;
				else if (to_multi)
					current_x *= value;
				else
					current_x = value;
			}
			
			if (axis == 'y'){
				if (to_add)
					current_y += value;
				else if (to_subtract)
					current_y -= value;
				else if (to_multi)
					current_y *= value;
				else
					current_y = value;
			}
			cursor = endptr;
		}


		//continue if at the end of a line
		if (*cursor == ';')
			cursor++;

		while (*cursor == '\n' || *cursor == '\r')
			cursor++;
	}

	C2D_SpriteSetPos(&sprites[object_index].spr, current_x, current_y);
}

//runs the create code
void RunGML_create(const char* code, int defIndex)
{
	//Select next object instance
	static bool did_create[MAX_SPRITES] = {0};
	static int create_cursor = 0;
	int object_index = runner_next_object_index(&create_cursor, defIndex);

	if (object_index < 0) 
		return;

	//check and set if the creates ran
	if (did_create[object_index]) 
		return;
	did_create[object_index] = true;



	//run the code
	runner_apply_xy_code(object_index, code);
}

void RunGML_step(const char* code, int defIndex)
{
	//Select next object instance
	static int step_cursor = 0;
	int object_index = runner_next_object_index(&step_cursor, defIndex);

	if (object_index < 0)
		return;



	//run the code
	runner_apply_xy_code(object_index, code);
}


//runs all the functions and submits the code for them
void RunGML(){
	const cJSON* objs = cJSON_GetObjectItemCaseSensitive(g_root, "Objects");
	const cJSON* all  = cJSON_GetObjectItemCaseSensitive(objs, "all_objects");
	const cJSON* object = NULL;
	int defIndex = 0;

	cJSON_ArrayForEach(object, all)
	{
		const cJSON* code_create = cJSON_GetObjectItemCaseSensitive(object, "CreateCode");
		const cJSON* code_step   = cJSON_GetObjectItemCaseSensitive(object, "StepCode");

		if (code_create && cJSON_IsString(code_create) && code_create->valuestring && code_create->valuestring[0] != '\0')
			RunGML_create(code_create->valuestring, defIndex);

		if (code_step && cJSON_IsString(code_step) && code_step->valuestring && code_step->valuestring[0] != '\0')
			RunGML_step(code_step->valuestring, defIndex);

		defIndex++;
	}
}
