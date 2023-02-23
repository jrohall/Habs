#include "stats_window.h"
#include "clay_settings.h"
#include "habit_list.h"

Window *stats_window;
TextLayer *stats_text;
// I KNOW this is not the best way of doing this, please forgive me, I am new to pebble development!
TextLayer *habit_0, *habit_1, *habit_2, *habit_3, *habit_4, *habit_5, *habit_6, *habit_7, *habit_8, *habit_9;

void stats_window_load(Window *window){
  // unfortunately, I have to manage each habit individually...
  char *habit0_label = load_habit0();
  char *habit1_label = load_habit1();
  char *habit2_label = load_habit2();
  char *habit3_label = load_habit3();
  char *habit4_label = load_habit4();
  char *habit5_label = load_habit5();
  char *habit6_label = load_habit6();
  char *habit7_label = load_habit7();
  char *habit8_label = load_habit8();
  char *habit9_label = load_habit9();
  //char habArr[NUM_ELEMENTS][MAX_STRING_LENGTH] = {habit0_label, habit1_label, habit2_label, habit3_label, habit4_label, habit5_label, habit6_label, habit7_label, habit8_label, habit9_label};

	Layer *window_layer = window_get_root_layer(window);

	int label_x = 5;
  stats_text = text_layer_create(GRect(label_x, 5, 148, 166));
  // label buffer
  //char habits_labels[10*10];
  //memset(habits_labels, 0, sizeof(habits_labels));
  //for (int i = 0; i < 10; i++) {
  //  strcat(habits_labels, habits_clay_list[i]);
  //  strcat(habits_labels, "\n");
  //}
  text_layer_set_text(stats_text, habit0_label);
  text_layer_set_text_color(stats_text, GColorBlack);
  text_layer_set_background_color(stats_text, GColorClear);
  //text_layer_set_text_alignment(stats_text, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(stats_text));

  // loading in the stats from the habits page
  int *habit_stats = load_data();

  // adding a buffer for the converted nums
  static char habit_buff[16];
	snprintf(habit_buff, sizeof(habit_buff), "%d", habit_stats[0]);
  habit_0 = text_layer_create(GRect(label_x + 65, 5, 148, 166));
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
