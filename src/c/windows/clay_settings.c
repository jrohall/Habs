#include "clay_settings.h"

#define SETTINGS_KEY 1
#define NUM_ELEMENTS 10
#define MAX_STRING_LENGTH 10

char habits_clay_list[NUM_ELEMENTS][MAX_STRING_LENGTH];
int total_elements = 0;

// define every variable that will be covered under settings
typedef struct ClaySettings {

	// ex. int temperature;
	char habit0[10];
	/*char habit1[10];
	char habit2[10];
	char habit3[10];
	char habit4[10];
	char habit5[10];
	char habit6[10];
	char habit7[10];
	char habit8[10];
	char habit9[10];*/
	
} ClaySettings;

static ClaySettings settings;

// set default settings values for each variable listed under settings
static void default_settings(){

	// ex. settings.temperature = 0;
	strcpy(settings.habit0, "Habit 0");

}

// read settings for persistent storage
static void load_settings(){

	// call default settings
	default_settings();
	// read settings if they already exist
	persist_read_data(SETTINGS_KEY, &settings, sizeof(settings));

}

// write settings to persistent storage
static void write_settings(){

	// writing with SETTINGS_KEY
	persist_write_data(SETTINGS_KEY, &settings, sizeof(settings));

}

// inbox received callback
static void inbox_r(DictionaryIterator *iterator, void *context) {

	// the parameter i would be the iterator in our code, so we could set temp like so:
	/*
	Tuple *temperature_t = dict_find(i, MESSAGE_KEY_Temperature);
	if(temperature_t){
		settings.temperature = atoi(temperature_t->value->cstring);
	} 
	*/

	Tuple *habit0_tuple = dict_find(iterator, MESSAGE_KEY_habit0);
	if(habit0_tuple && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit0_tuple->value->cstring);
		total_elements++;
	}

	//save all the settings recieved.
	write_settings();
}

static void inbox_d(AppMessageResult r, void *context) {
	APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
}

static void outbox_f(DictionaryIterator *iterator, AppMessageResult r, void *context){
	APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send failed!");
}
static void outbox_s(DictionaryIterator *iterator, void *context){
	APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send success!");
}

static void init(){

	// we want to load our settings first
	load_settings();

	// then we want to set our application callbacks
	app_message_register_inbox_received(inbox_r);
	app_message_register_inbox_dropped(inbox_d);
	app_message_register_outbox_failed(outbox_f);
	app_message_register_outbox_sent(outbox_s);
}

static void deinit(){
	// nothing to de-init here! no window or layer data
}

void load_habits(){
	init();
	deinit();
	//char habits[10][10] = {habit0, habit1, habit2, habit3, habit4, habit5, habit6, habit7, habit8, habit9};
	//return habits_clay_list;
}


// Next: MESSAGE_KEY_habit0 is apparently "undeclared", although it is defined in both package.json and appinfo.json
