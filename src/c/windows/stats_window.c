#include "stats_window.h"
#include "clay_settings.h"
#include "habit_list.h"

// window
Window *stats_window;
// labels
TextLayer *title1, *title2;
TextLayer *layer0, *layer1, *layer2, *layer3, *layer4, *layer5, *layer6, *layer7, *layer8, *layer9;
// stats
TextLayer *habit_0, *habit_1, *habit_2, *habit_3, *habit_4, *habit_5, *habit_6, *habit_7, *habit_8, *habit_9;
// lines
GBitmap *graph_bitmap;
BitmapLayer *graph_layer;

void canvas_draw(Layer *layer, GContext *ctx){
  // drawing the lines :)
  graphics_context_set_stroke_color(ctx, GColorBlack);
  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_context_set_stroke_width(ctx, 5);
  GPoint start_1 = GPoint(0, 16);
  GPoint end_1 = GPoint(148, 16);
  graphics_draw_line(ctx, start_1, end_1);
}

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

  // grabbing the window layer to apply the text
	Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  // setting the lines
  graph_bitmap = gbitmap_create_with_resource(RESOURCE_ID_GRAPH);
  graph_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(graph_layer, graph_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(graph_layer));

  // chart headings

  title1 = text_layer_create(GRect(15, 1, 148, 166));
  text_layer_set_text(title1, "Habits");
  text_layer_set_text_color(title1, GColorBlack);
  text_layer_set_background_color(title1, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(title1));

  title2 = text_layer_create(GRect(80, 1, 148, 166));
  text_layer_set_text(title2, "Streaks");
  text_layer_set_text_color(title2, GColorBlack);
  text_layer_set_background_color(title2, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(title2));


  // settings x and y values, change_y and change_x will be how much the labels will change with respect to the original values
	int label_x = 15;
  int label_y = 15;
  int change_y = 15;
  int change_x = 80;

  // loading in the stats from the habits page
  int *habit_stats = load_data();

  layer0 = text_layer_create(GRect(label_x, label_y, 148, 166));
  text_layer_set_text(layer0, habit0_label);
  text_layer_set_text_color(layer0, GColorBlack);
  text_layer_set_background_color(layer0, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(layer0));

  static char habit_buff0[16];
  snprintf(habit_buff0, sizeof(habit_buff0), "%d", habit_stats[0]);
  habit_0 = text_layer_create(GRect(label_x + change_x, label_y, 148, 166));
  text_layer_set_text(habit_0, habit_buff0);
  text_layer_set_font(habit_0, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_0, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_0));

  label_y = label_y + change_y;
  layer1 = text_layer_create(GRect(label_x, label_y, 148, 166));
  text_layer_set_text(layer1, habit1_label);
  text_layer_set_text_color(layer1, GColorBlack);
  text_layer_set_background_color(layer1, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(layer1));

  static char habit_buff1[16];
  snprintf(habit_buff1, sizeof(habit_buff1), "%d", habit_stats[1]);
  habit_1 = text_layer_create(GRect(label_x + change_x, label_y, 148, 166));
  text_layer_set_text(habit_1, habit_buff1);
  text_layer_set_font(habit_1, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_1, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_1));

  label_y = label_y + change_y;
  layer2 = text_layer_create(GRect(label_x, label_y, 148, 166));
  text_layer_set_text(layer2, habit2_label);
  text_layer_set_text_color(layer2, GColorBlack);
  text_layer_set_background_color(layer2, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(layer2));

  static char habit_buff2[16];
  snprintf(habit_buff2, sizeof(habit_buff2), "%d", habit_stats[2]);
  habit_2 = text_layer_create(GRect(label_x + change_x, label_y, 148, 166));
  text_layer_set_text(habit_2, habit_buff2);
  text_layer_set_font(habit_2, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_2, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_2));

  label_y = label_y + change_y;
  layer3 = text_layer_create(GRect(label_x, label_y, 148, 166));
  text_layer_set_text(layer3, habit3_label);
  text_layer_set_text_color(layer3, GColorBlack);
  text_layer_set_background_color(layer3, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(layer3));

  static char habit_buff3[16];
  snprintf(habit_buff3, sizeof(habit_buff3), "%d", habit_stats[3]);
  habit_3 = text_layer_create(GRect(label_x + change_x, label_y, 148, 166));
  text_layer_set_text(habit_3, habit_buff3);
  text_layer_set_font(habit_3, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_3, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_3));

  label_y = label_y + change_y;
  layer4 = text_layer_create(GRect(label_x, label_y, 148, 166));
  text_layer_set_text(layer4, habit4_label);
  text_layer_set_text_color(layer4, GColorBlack);
  text_layer_set_background_color(layer4, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(layer4));

  static char habit_buff4[16];
  snprintf(habit_buff4, sizeof(habit_buff4), "%d", habit_stats[4]);
  habit_4 = text_layer_create(GRect(label_x + change_x, label_y, 148, 166));
  text_layer_set_text(habit_4, habit_buff4);
  text_layer_set_font(habit_4, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_4, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_4));

  label_y = label_y + change_y;
  layer5 = text_layer_create(GRect(label_x, label_y, 148, 166));
  text_layer_set_text(layer5, habit5_label);
  text_layer_set_text_color(layer5, GColorBlack);
  text_layer_set_background_color(layer5, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(layer5));

  static char habit_buff5[16];
  snprintf(habit_buff5, sizeof(habit_buff5), "%d", habit_stats[5]);
  habit_5 = text_layer_create(GRect(label_x + change_x, label_y, 148, 166));
  text_layer_set_text(habit_5, habit_buff5);
  text_layer_set_font(habit_5, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_5, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_5));

  label_y = label_y + change_y;
  layer6 = text_layer_create(GRect(label_x, label_y, 148, 166));
  text_layer_set_text(layer6, habit6_label);
  text_layer_set_text_color(layer6, GColorBlack);
  text_layer_set_background_color(layer6, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(layer6));

  static char habit_buff6[16];
  snprintf(habit_buff6, sizeof(habit_buff6), "%d", habit_stats[6]);
  habit_6 = text_layer_create(GRect(label_x + change_x, label_y, 148, 166));
  text_layer_set_text(habit_6, habit_buff6);
  text_layer_set_font(habit_6, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_6, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_6));

  label_y = label_y + change_y;
  layer7 = text_layer_create(GRect(label_x, label_y, 148, 166));
  text_layer_set_text(layer7, habit7_label);
  text_layer_set_text_color(layer7, GColorBlack);
  text_layer_set_background_color(layer7, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(layer7));

  static char habit_buff7[16];
  snprintf(habit_buff7, sizeof(habit_buff7), "%d", habit_stats[7]);
  habit_7 = text_layer_create(GRect(label_x + change_x, label_y, 148, 166));
  text_layer_set_text(habit_7, habit_buff7);
  text_layer_set_font(habit_7, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_7, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_7));

  label_y = label_y + change_y;
  layer8 = text_layer_create(GRect(label_x, label_y, 148, 166));
  text_layer_set_text(layer8, habit8_label);
  text_layer_set_text_color(layer8, GColorBlack);
  text_layer_set_background_color(layer8, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(layer8));

  static char habit_buff8[16];
  snprintf(habit_buff8, sizeof(habit_buff8), "%d", habit_stats[8]);
  habit_8 = text_layer_create(GRect(label_x + change_x, label_y, 148, 166));
  text_layer_set_text(habit_8, habit_buff8);
  text_layer_set_font(habit_8, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_8, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_8));

  label_y = label_y + change_y;
  layer9 = text_layer_create(GRect(label_x, label_y, 148, 166));
  text_layer_set_text(layer9, habit9_label);
  text_layer_set_text_color(layer9, GColorBlack);
  text_layer_set_background_color(layer9, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(layer9));

  static char habit_buff9[16];
  snprintf(habit_buff9, sizeof(habit_buff9), "%d", habit_stats[9]);
  habit_9 = text_layer_create(GRect(label_x + change_x, label_y, 148, 166));
  text_layer_set_text(habit_9, habit_buff9);
  text_layer_set_font(habit_9, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  text_layer_set_background_color(habit_9, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(habit_9));

}

void stats_window_unload(Window *window){
	// destroy TextLayer
	text_layer_destroy(layer0);
  text_layer_destroy(layer1);
  text_layer_destroy(layer2);
  text_layer_destroy(layer3);
  text_layer_destroy(layer4);
  text_layer_destroy(layer5);
  text_layer_destroy(layer6);
  text_layer_destroy(layer7);
  text_layer_destroy(layer8);
  text_layer_destroy(layer9);
  text_layer_destroy(habit_0);
  text_layer_destroy(habit_1);
  text_layer_destroy(habit_2);
  text_layer_destroy(habit_3);
  text_layer_destroy(habit_4);
  text_layer_destroy(habit_5);
  text_layer_destroy(habit_6);
  text_layer_destroy(habit_7);
  text_layer_destroy(habit_8);
  text_layer_destroy(habit_9);
  text_layer_destroy(title1);
  text_layer_destroy(title2);

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
