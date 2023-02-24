#include "options_window.h"

Window *options_window;
TextLayer *options_text;

void options_window_load(Window *window){
	options_text = text_layer_create(GRect(10, 60, 148, 168));
  text_layer_set_text(options_text, "Visit the pebble app\n to change settings");
  text_layer_set_text_color(options_text, GColorBlack);
  text_layer_set_background_color(options_text, GColorClear);
  layer_add_child(window_get_root_layer(options_window), text_layer_get_layer(options_text));
}
 
void options_window_unload(Window *window){
	//Destroy GBitmap
	text_layer_destroy(options_text);
}
 
void options_window_push() {
  if(!options_window) {
    options_window = window_create();
    window_set_window_handlers(options_window, (WindowHandlers) {
        .load = options_window_load,
        .unload = options_window_unload,
    });
  }
  window_stack_push(options_window, true);
}
