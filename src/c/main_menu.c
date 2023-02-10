#include <pebble.h>
 
static Window *window;
static MenuLayer *menu_layer;
 

// Menus need many inputs in order to function properly, which is where these callbacks come into play
// These callbacks must be defined BEFORE (above) tthe window_load function

// alters what is drawn in a row based on which index it is
// we need to tell the function which row is which based on a switch method:
void draw_row_callback(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{
    //Which row is it?
    switch(cell_index->row)
    {
    case 0:
        menu_cell_basic_draw(ctx, cell_layer, "Exercise", "Follow muscle growth regiment.", NULL);
        break;
    case 1:
        menu_cell_basic_draw(ctx, cell_layer, "Read", "25 Pages per day", NULL);
        break;
    case 2:
        menu_cell_basic_draw(ctx, cell_layer, "Study", "Continue online class", NULL);
        break;
    case 3:
        menu_cell_basic_draw(ctx, cell_layer, "Meditate", "Five Minutes after workout.", NULL);
        break;
    case 4:
        menu_cell_basic_draw(ctx, cell_layer, "Code", "Spend at least one hour on project", NULL);
        break;
    }
    // ideally, the NULL methods would be replaced with a bitmap icon, but we arent doing that here (for now)
}
 
 // simply returns the number of rows wanted in a list
uint16_t num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *callback_context)
{
  return 5;
}
 
void select_click_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context)
{
    //Get which row
    int which = cell_index->row;
 
    //The array that will hold the on/off vibration times
    uint32_t segments[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 
    //Build the pattern (milliseconds on and off in alternating positions)
    for(int i = 0; i < which + 1; i++)
    {
        segments[2 * i] = 200;
        segments[(2 * i) + 1] = 100;
    }
    
    
    //Create a VibePattern data structure
    VibePattern pattern = {
        .durations = segments,
        .num_segments = 16
    };
 
    //Do the vibration pattern!
    vibes_enqueue_custom_pattern(pattern);
    
}

// now that these callbacks are in place, we can then add it to our main window, this will take multiple steps
/*

1. create MenuLayer, and assign it a global pointer
2. allow the layer to accept clicks from it's window
3. set proper callbacks to allow the layer to get what it needs
4. add MenuLayer to the main window

*/


// observe how this is carried out below:
void window_load(Window *window)
{
    //Create it - 12 is approx height of the top bar
    menu_layer = menu_layer_create(GRect(0, 0, 144, 168 - 16));
 
    //Let it receive clicks
    menu_layer_set_click_config_onto_window(menu_layer, window);
 
    //Give it its callbacks
    MenuLayerCallbacks callbacks = {
        .draw_row = (MenuLayerDrawRowCallback) draw_row_callback,
        .get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) num_rows_callback,
        .select_click = (MenuLayerSelectCallback) select_click_callback
    };
    menu_layer_set_callbacks(menu_layer, NULL, callbacks);
    

    //Add to Window
    layer_add_child(window_get_root_layer(window), menu_layer_get_layer(menu_layer));
}
 
// and, of course, dont forgett to de-init the layer!
void window_unload(Window *window)
{
  menu_layer_destroy(menu_layer);
}
 
void init()
{
    window = window_create();
    WindowHandlers handlers = {
        .load = window_load,
        .unload = window_unload
    };
    window_set_window_handlers(window, (WindowHandlers) handlers);
    window_stack_push(window, true);
}
 
void deinit()
{
    window_destroy(window);
}
 
int main(void)
{
    init();
    app_event_loop();
    deinit();
}