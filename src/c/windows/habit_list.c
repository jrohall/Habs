#include "habit_list.h"
#include "clay_settings.h"

static Window *habit_window;
static MenuLayer *habit_menu_layer;
static GBitmap *unchecked_icon, *checked_icon, *white_checked_icon, *white_unchecked_icon;
static bool s_selections[HABIT_WINDOW_ROWS];
int habit_stats[10];

// in order to save the habit data to persistant storage, there are a few functions that need to be declared..
void save_stats(){
    persist_write_data(0, habit_stats, sizeof(habit_stats));
}
// this function is included in the header, which can be accessed from the stats page!
int * load_data(){
    persist_read_data(0, habit_stats, sizeof(habit_stats));
    return habit_stats;
}


// Menus need many inputs in order to function properly, which is where these callbacks come into play
// These callbacks must be defined BEFORE (above) tthe window_load function

// alters what is drawn in a row based on which index it is
// we need to tell the function which row is which based on a switch method:
void h_draw_row_callback(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{

	if(cell_index->row == HABIT_WINDOW_ROWS) {
    // i am using a submit button for a user to submit which habits they have complete, which
    // should (hopefully) connect to another window which provides statistics on the user's habits
    	menu_cell_basic_draw(ctx, cell_layer, "Submit", "(submit checked habits)", NULL);
  	} 
  	else {
	    // main habits in list (must integrate custom user list later)
	    static char habit_list_buff[16];
	    snprintf(habit_list_buff, sizeof(habit_list_buff), "Habit %d", (int)cell_index->row);
	    menu_cell_basic_draw(ctx, cell_layer, habit_list_buff, NULL, NULL);
	}

    // setting the checked and unchecked pointers
    GBitmap *un_ptr = unchecked_icon;
    GBitmap *ch_ptr = checked_icon;

    // grab the dimensions of the checkboxes and the rows
    GRect bounds = layer_get_bounds(cell_layer);
    GRect bitmap_bounds = gbitmap_get_bounds(un_ptr);

    // draw the check boxes
    GRect ptr_dim = GRect(bounds.size.w - (2 * HABIT_BOX_SIZE), (bounds.size.h / 2) - (HABIT_BOX_SIZE / 2), HABIT_BOX_SIZE, HABIT_BOX_SIZE);

    // check if selected, invert colors if so
    
    if(menu_cell_layer_is_highlighted(cell_layer)) {
        graphics_context_set_stroke_color(ctx, GColorWhite);
        //invert the checker bitmaps
        un_ptr = white_unchecked_icon;
        ch_ptr = white_checked_icon;
    }

    // draw an unchecked box if the row is not the submission row
    if(cell_index->row != HABIT_WINDOW_ROWS){
        graphics_context_set_compositing_mode(ctx, GCompOpSet);
        graphics_draw_bitmap_in_rect(ctx, un_ptr, GRect(ptr_dim.origin.x, ptr_dim.origin.y - 3, bitmap_bounds.size.w, bitmap_bounds.size.h));
    }
    // draw the selected checkbox if a (non-submit) row is selected
    if(s_selections[cell_index->row] && cell_index->row != HABIT_WINDOW_ROWS) {
        graphics_context_set_compositing_mode(ctx, GCompOpSet);
        graphics_draw_bitmap_in_rect(ctx, ch_ptr, GRect(ptr_dim.origin.x, ptr_dim.origin.y - 3, bitmap_bounds.size.w, bitmap_bounds.size.h));
    }

    // BUG LOG:
    // - The check boxes only change colors when cell selection moves
    // - The check boxes are slightly off center
}

// simply returns the number of rows wanted in a list
uint16_t h_num_rows_callback(MenuLayer *habit_menu_layer, uint16_t section_index, void *callback_context)
{
  return HABIT_WINDOW_ROWS + 1;
}

void h_select_click_callback(MenuLayer *habit_menu_layer, MenuIndex *cell_index, void *callback_context)
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


    // check if the submit button is pressed firstt, then check the other rows
    if(cell_index->row == HABIT_WINDOW_ROWS) {
    // add to checked boxes statistics page (will do after this window is complete)

    // pebble UI example loop:
    for(int i = 0; i < HABIT_WINDOW_ROWS; i++) {
        if(s_selections[i]) {
            habit_stats[i] += 1;
        }
        //APP_LOG(APP_LOG_LEVEL_INFO, "Option %d was %s", i, (s_selections[i] ? "selected" : "not selected"));
    }
    save_stats();

    // return to previous window (in this case, the main menu.)
    window_stack_pop(true);
  } else {
    // this is for the rest of the habits, we need to know when they are being checked and unchecked.
    int row = cell_index->row;
    s_selections[row] = !s_selections[row];
    //menu_layer_reload_data(habit_menu_layer); // ideally reloads the window??
  }
    
}

// now that these callbacks are in place, we can then add it to our main window, this will take multiple steps
/*

1. create MenuLayer, and assign it a global pointer
2. allow the layer to accept clicks from it's window
3. set proper callbacks to allow the layer to get what it needs
4. add MenuLayer to the main window

*/


// observe how this is carried out below:
void habit_window_load(Window *window){
    // create it
    habit_menu_layer = menu_layer_create(GRect(0, 0, 144, 168));
 
    // let it receive clicks
    menu_layer_set_click_config_onto_window(habit_menu_layer, habit_window);

    // bitmap initializations
    unchecked_icon = gbitmap_create_with_resource(RESOURCE_ID_UNCHECKED);
    white_unchecked_icon = gbitmap_create_with_resource(RESOURCE_ID_WHITE_UNCHECKED);
    checked_icon = gbitmap_create_with_resource(RESOURCE_ID_CHECKED);
    white_checked_icon = gbitmap_create_with_resource(RESOURCE_ID_WHITE_CHECKED);
 
    //Give it its callbacks
    MenuLayerCallbacks callbacks = {
        .draw_row = (MenuLayerDrawRowCallback) h_draw_row_callback,
        .get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) h_num_rows_callback,
        .select_click = (MenuLayerSelectCallback) h_select_click_callback
    };
    menu_layer_set_callbacks(habit_menu_layer, NULL, callbacks);
    

    //Add to Window
    layer_add_child(window_get_root_layer(habit_window), menu_layer_get_layer(habit_menu_layer));
}
 
// and, of course, dont forgett to de-init the layer!
void habit_window_unload(Window *window){
  menu_layer_destroy(habit_menu_layer);
  gbitmap_destroy(checked_icon);
  gbitmap_destroy(unchecked_icon);
}
 
void habit_list_push() {
  if(!habit_window) {
    habit_window = window_create();
    window_set_window_handlers(habit_window, (WindowHandlers) {
        .load = habit_window_load,
        .unload = habit_window_unload,
    });
  }
  window_stack_push(habit_window, true);
}
