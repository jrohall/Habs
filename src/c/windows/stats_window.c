#include "stats_window.h"
#include "global.h"
#include "habit_list.h"

Window *stats_window;
TextLayer *stats_text;
// I KNOW this is not the best way of doing this, please forgive me, I am new to pebble development!
TextLayer *habit_0, *habit_1, *habit_2, *habit_3, *habit_4, *habit_5, *habit_6, *habit_7, *habit_8, *habit_9;
//extern int habit_stats[10];

void stats_window_load(Window *window){
	Layer *window_layer = window_get_root_layer(window);

  stats_text = text_layer_create(GRect(5, 5, 148, 166));
  text_layer_set_text(stats_text, "Habit 1: \nHabit 2: \nHabit 3: \nHabit 4: \nHabit 5: \nHabit 6: \nHabit 7: \nHabit 8: \nHabit 9: \nHabit 10: \n");
  text_layer_set_background_color(stats_text, GColorClear);
  //text_layer_set_text_alignment(stats_text, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(stats_text));

  // again, I know this hurts :,)
  int *habit_stats = load_data();
  static char habit_buff[16];
	snprintf(habit_buff, sizeof(habit_buff), "%d", habit_stats[0]);
  habit_0 = text_layer_create(GRect(70, 80, 148, 166));
  text_layer_set_text(habit_0, habit_buff);
  text_layer_set_font(habit_0, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_0, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_0));

}
 
void stats_window_unload(Window *window){
	//Destroy TextLayer
	text_layer_destroy(stats_text);
}
 
void stats_window_push() {
  if(!stats_window) {
    stats_window = window_create();
    window_set_window_handlers(stats_window, (WindowHandlers) {
        .load = stats_window_load,
        .unload = stats_window_unload,
    });
  }
  window_stack_push(stats_window, true);
}
