#include "clay_settings.h"

#define SETTINGS_KEY 1
#define NUM_ELEMENTS 10
#define MAX_STRING_LENGTH 10


char habits_clay_list[NUM_ELEMENTS][MAX_STRING_LENGTH];
int total_elements = 0;

// define every variable that will be covered under settings
typedef struct ClaySettings {

	// ex. int temperature;
	char Habit0[10];
	char Habit1[10];
	char Habit2[10];
	char Habit3[10];
	char Habit4[10];
	char Habit5[10];
	char Habit6[10];
	char Habit7[10];
	char Habit8[10];
	char Habit9[10];
	
} ClaySettings;

static ClaySettings settings;

// set default settings values for each variable listed under settings
static void default_settings(){

	// ex. settings.temperature = 0;
	strcpy(settings.Habit0, "Habit 0");
	strcpy(settings.Habit1, "Habit 1");
	strcpy(settings.Habit2, "Habit 2");
	strcpy(settings.Habit3, "Habit 3");
	strcpy(settings.Habit4, "Habit 4");
	strcpy(settings.Habit5, "Habit 5");
	strcpy(settings.Habit6, "Habit 6");
	strcpy(settings.Habit7, "Habit 7");
	strcpy(settings.Habit8, "Habit 8");
	strcpy(settings.Habit9, "Habit 9");

}


// here we are going to create a function that will be able to set an input from clay to a string, used in the inbox_r function
static void set_habit_text(char * hab, const char * text){
	//int length = get_text_length(text);
	int index = 0;
	while(MAX_STRING_LENGTH > index){
		hab[index] = text[index];
		index++;
	}
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
	// habit 0
	Tuple *habit0_t = dict_find(iterator, MESSAGE_KEY_Habit0);
	if(habit0_t && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit0_t->value->cstring);
		char * habit_0_text = habit0_t->value->cstring;
		if(strlen(habit_0_text) == 0){
			// set default text
			strcpy(settings.Habit0, "Habit 0");
		}
		else{
			// set user's specified text
			set_habit_text(settings.Habit0, habit_0_text);
		}
		total_elements++;
	}
	// habit 1
	Tuple *habit1_t = dict_find(iterator, MESSAGE_KEY_Habit1);
	if(habit1_t && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit1_t->value->cstring);
		char * habit_1_text = habit1_t->value->cstring;
		if(strlen(habit_1_text) == 0){
			// set default text
			strcpy(settings.Habit1, "Habit 1");
		}
		else{
			// set user's specified text
			set_habit_text(settings.Habit1, habit_1_text);
		}
		total_elements++;
	}
	// habit 2
	Tuple *habit2_t = dict_find(iterator, MESSAGE_KEY_Habit2);
	if(habit2_t && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit2_t->value->cstring);
		char * habit_2_text = habit2_t->value->cstring;
		if(strlen(habit_2_text) == 0){
			// set default text
			strcpy(settings.Habit2, "Habit 2");
		}
		else{
			// set user's specified text
			set_habit_text(settings.Habit2, habit_2_text);
		}
		total_elements++;
	}
	// habit 3
	Tuple *habit3_t = dict_find(iterator, MESSAGE_KEY_Habit3);
	if(habit3_t && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit3_t->value->cstring);
		char * habit_3_text = habit3_t->value->cstring;
		if(strlen(habit_3_text) == 3){
			// set default text
			strcpy(settings.Habit3, "Habit 3");
		}
		else{
			// set user's specified text
			set_habit_text(settings.Habit3, habit_3_text);
		}
		total_elements++;
	}
	// habit 4
	Tuple *habit4_t = dict_find(iterator, MESSAGE_KEY_Habit4);
	if(habit4_t && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit4_t->value->cstring);
		char * habit_4_text = habit4_t->value->cstring;
		if(strlen(habit_4_text) == 0){
			// set default text
			strcpy(settings.Habit4, "Habit 4");
		}
		else{
			// set user's specified text
			set_habit_text(settings.Habit4, habit_4_text);
		}
		total_elements++;
	}
	// habit 5
	Tuple *habit5_t = dict_find(iterator, MESSAGE_KEY_Habit5);
	if(habit5_t && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit5_t->value->cstring);
		char * habit_5_text = habit5_t->value->cstring;
		if(strlen(habit_5_text) == 5){
			// set default text
			strcpy(settings.Habit5, "Habit 5");
		}
		else{
			// set user's specified text
			set_habit_text(settings.Habit5, habit_5_text);
		}
		total_elements++;
	}
	// habit 6
	Tuple *habit6_t = dict_find(iterator, MESSAGE_KEY_Habit6);
	if(habit6_t && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit6_t->value->cstring);
		char * habit_6_text = habit6_t->value->cstring;
		if(strlen(habit_6_text) == 0){
			// set default text
			strcpy(settings.Habit6, "Habit 6");
		}
		else{
			// set user's specified text
			set_habit_text(settings.Habit6, habit_6_text);
		}
		total_elements++;
	}
	// habit 7
	Tuple *habit7_t = dict_find(iterator, MESSAGE_KEY_Habit7);
	if(habit7_t && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit7_t->value->cstring);
		char * habit_7_text = habit7_t->value->cstring;
		if(strlen(habit_7_text) == 0){
			// set default text
			strcpy(settings.Habit7, "Habit 7");
		}
		else{
			// set user's specified text
			set_habit_text(settings.Habit7, habit_7_text);
		}
		total_elements++;
	}
	// habit 8
	Tuple *habit8_t = dict_find(iterator, MESSAGE_KEY_Habit8);
	if(habit8_t && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit8_t->value->cstring);
		char * habit_8_text = habit8_t->value->cstring;
		if(strlen(habit_8_text) == 0){
			// set default text
			strcpy(settings.Habit8, "Habit 8");
		}
		else{
			// set user's specified text
			set_habit_text(settings.Habit8, habit_8_text);
		}
		total_elements++;
	}
	// habit 9
	Tuple *habit9_t = dict_find(iterator, MESSAGE_KEY_Habit9);
	if(habit9_t && total_elements < NUM_ELEMENTS){
		snprintf(habits_clay_list[total_elements], MAX_STRING_LENGTH, "%s", habit9_t->value->cstring);
		char * habit_9_text = habit9_t->value->cstring;
		if(strlen(habit_9_text) == 0){
			// set default text
			strcpy(settings.Habit9, "Habit 9");
		}
		else{
			// set user's specified text
			set_habit_text(settings.Habit9, habit_9_text);
		}
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

	// recieving and whatnot
	const int inbox_size = 128;
	const int outbox_size = 128;
	app_message_open(inbox_size, outbox_size);
}

static void deinit(){
	// nothing to de-init here! no window or layer data
}

void load_clay(){
	init();
	deinit();
}