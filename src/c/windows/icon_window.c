#include "icon_window.h"

Window *icon_window;
GBitmap *icon_bitmap;
BitmapLayer *icon_layer;

void icon_window_load(Window *window){
	//Load bitmaps into GBitmap structures
	//The ID you chose when uploading is prefixed with 'RESOURCE_ID_'
	icon_bitmap = gbitmap_create_with_resource(RESOURCE_ID_GRAPH);
	 
	//Create BitmapLayers to show GBitmaps and add to Window
	//Sample images are 127 x 129 pixels
	icon_layer = bitmap_layer_create(GRect(0, 0, 180, 180));
	bitmap_layer_set_bitmap(icon_layer, icon_bitmap);
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(icon_layer));
	 
}
 
void icon_window_unload(Window *window){
	//Destroy GBitmap
	gbitmap_destroy(icon_bitmap);
	 
	//Destroy BitmapLayer
	bitmap_layer_destroy(icon_layer);
}
 
void icon_window_push() {
  if(!icon_window) {
    icon_window = window_create();
    window_set_window_handlers(icon_window, (WindowHandlers) {
        .load = icon_window_load,
        .unload = icon_window_unload,
    });
  }
  window_stack_push(icon_window, true);
}

/*
void init()
{
  //Initialize the app elements here!
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  //window_set_window_handlers(window, (WindowHandlers) handlers);
  window_stack_push(window, true);
}
 
void deinit()
{
  //De-initialize elements here to save memory!
	window_destroy(window);
}
 
int main(void)
{
  init();
  app_event_loop();
  deinit();
}
*/