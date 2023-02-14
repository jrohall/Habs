#pragma once

#include <pebble.h>

#define HABIT_WINDOW_ROWS	5
#define HABIT_BOX_SIZE		12
#define HABIT_ROW_HEIGHT	44

void habit_list_push();
int * get_stats();