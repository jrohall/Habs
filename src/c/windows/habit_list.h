#pragma once

#include <pebble.h>

#define HABIT_WINDOW_ROWS	10
#define HABIT_BOX_SIZE		12
#define HABIT_ROW_HEIGHT	44

void habit_list_push();
int * load_data();