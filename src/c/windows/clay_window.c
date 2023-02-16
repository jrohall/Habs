#include "clay_window.h"

static ClaySettings settings;
int habit_list[10];

static void settings_init() {
	// settings initialization with default values
	clay_settings_init(&settings);

	// loading settings, then match keys from message key from .json file
	// Habit 0
	if(persist_exist(MESSAGE_KEY_Habit0)){
		persist_read_string(MESSAGE_KEY_Habit0, settings.Habit0, sizeof(settings.Habit0));
	}
	else{
		strncpy(settings.Habit0, "Habit 0", sizeof(settings.Habit0));
	}
	/*
	// Habit 1
	if(persist_exist(MESSAGE_KEY_Habit1)){
		persist_read_string(MESSAGE_KEY_Habit1, settings.Habit1, sizeof(settings.Habit1));
	}
	else{
		strncpy(settings.Habit1, "Habit 1", sizeof(settings.Habit1));
	}
	// Habit 2
	if(persist_exist(MESSAGE_KEY_Habit2)){
		persist_read_string(MESSAGE_KEY_Habit2, settings.Habit2, sizeof(settings.Habit2));
	}
	else{
		strncpy(settings.Habit2, "Habit 2", sizeof(settings.Habit2));
	}
	// Habit 3
	if(persist_exist(MESSAGE_KEY_Habit3)){
		persist_read_string(MESSAGE_KEY_Habit3, settings.Habit3, sizeof(settings.Habit3));
	}
	else{
		strncpy(settings.Habit3, "Habit 3", sizeof(settings.Habit3));
	}
	// Habit 4
	if(persist_exist(MESSAGE_KEY_Habit4)){
		persist_read_string(MESSAGE_KEY_Habit4, settings.Habit4, sizeof(settings.Habit4));
	}
	else{
		strncpy(settings.Habit4, "Habit 4", sizeof(settings.Habit4));
	}
	//Habit 5
	if(persist_exist(MESSAGE_KEY_Habit5)){
		persist_read_string(MESSAGE_KEY_Habit5, settings.Habit5, sizeof(settings.Habit5));
	}
	else{
		strncpy(settings.Habit5, "Habit 5", sizeof(settings.Habit5));
	}
	// Habit 6
	if(persist_exist(MESSAGE_KEY_Habit6)){
		persist_read_string(MESSAGE_KEY_Habit6, settings.Habit6, sizeof(settings.Habit6));
	}
	else{
		strncpy(settings.Habit6, "Habit 6", sizeof(settings.Habit6));
	}
	// Habit 7
	if(persist_exist(MESSAGE_KEY_Habit7)){
		persist_read_string(MESSAGE_KEY_Habit7, settings.Habit7, sizeof(settings.Habit7));
	}
	else{
		strncpy(settings.Habit7, "Habit 7", sizeof(settings.Habit7));
	}
	// Habit 8
	if(persist_exist(MESSAGE_KEY_Habit8)){
		persist_read_string(MESSAGE_KEY_Habit8, settings.Habit8, sizeof(settings.Habit8));
	}
	else{
		strncpy(settings.Habit8, "Habit 8", sizeof(settings.Habit8));
	}
	// Habit 9
	if(persist_exist(MESSAGE_KEY_Habit9)){
		persist_read_string(MESSAGE_KEY_Habit9, settings.Habit9, sizeof(settings.Habit9));
	}
	else{
		strncpy(settings.Habit9, "Habit 9", sizeof(settings.Habit9));
	}*/

}

// returns the habits to habit stats and habit_list windows
int * get_habits(){
	return habit_list;
}