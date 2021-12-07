#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "hall.h"
#include "button.h"
#include "gameScreenContext.h"
#include "bigTextLabel.h"


int SCREEN_W = 1300;
int SCREEN_H = 700;
int testJ1 = 0;
int testJ2 = 0;
const float FPS = 60;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;

ALLEGRO_COLOR white = al_map_rgb_f(1.0, 1.0, 1.0);
ALLEGRO_COLOR red = al_map_rgb_f(1.0, 1.0, 1.0);
ALLEGRO_COLOR blue = al_map_rgb_f(1.0, 1.0, 1.0);
ALLEGRO_COLOR yellow = al_map_rgb_f(1.0, 1.0, 0);
bool running = true;
bool redraw = true;

int init_allegro(void)
{
		// Initialize allegro
		if (!al_init()) {
			fprintf(stderr, "Failed to initialize allegro.\n");
			return 1;
		}

		if (!al_init_image_addon()) {
			al_uninstall_system();
			fprintf(stdout, "Error Critical!");
			return 0;
		}

		if (!al_install_keyboard()) {
			al_uninstall_system();
		    fprintf(stdout, "Error Critical!");
			return 0;
		}

		if (!al_install_mouse()) {
			al_uninstall_system();
			fprintf(stdout, "Error Critical!");
			return 0;
		}

		// Initialize the timer
		timer = al_create_timer(1.0 / FPS);
		if (!timer) {
			fprintf(stderr, "Failed to create timer.\n");
			return 1;
		}

		ALLEGRO_MONITOR_INFO info;
		al_get_monitor_info(0, &info);
		if(((info.x2 - info.x1) > 0)&&((info.y2 - info.y1) > 0)){ // Verify if the resolution is ok...
			SCREEN_W = info.x2 - info.x1 - 100;
			SCREEN_H = info.y2 - info.y1 - 100;
		}

		// Create the display
		display = al_create_display(SCREEN_W, SCREEN_H);
		if (!display) {
			fprintf(stderr, "Failed to create display.\n");
			return 1;
		}

		// Create the event queue
		event_queue = al_create_event_queue();
		if (!event_queue) {
			fprintf(stderr, "Failed to create event queue.");
			return 1;
		}

		// Register event sources
		al_register_event_source(event_queue, al_get_display_event_source(display));
		al_register_event_source(event_queue, al_get_timer_event_source(timer));
	    al_register_event_source(event_queue, al_get_keyboard_event_source());
	    al_register_event_source(event_queue, al_get_mouse_event_source());

		// Display a black screen
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_flip_display();

		// Start the timer
		al_start_timer(timer);

		al_init_primitives_addon();

		return 1;
}

int main()
{
	init_allegro();
	gameScreenContext gameMainScreen;
	gameMainScreen.setScreenSize(SCREEN_W, SCREEN_H);
	gameMainScreen.setGlobalTimer(timer);
	int blocSize = 10;
	int numBlocW = (SCREEN_W-100)/blocSize;
	int numBlocH = (SCREEN_H-170)/blocSize;
	hall hall1(50, 150, blocSize, numBlocW, numBlocH);
	myButton playButton(570, 40, 100, 100);
	myButton resetButton(680, 40, 100, 100);
	myButton restoreButton(800, 40, 100, 100);
	myButton funButton(910, 40, 100, 100);
	myButton saveButton(1020, 40, 100, 100);
	myButton loadButton(1130, 40, 100, 100);
	myButton prevSpeedButton(300,108,32,32);
	myButton nextSpeedButton(230,108,32,32);
	bigTestLabel text1(50,50);

	text1.insertText("Life Game!");
	text1.insertText("");
	text1.insertText("3 WHITE neighbors and the BLACK becomes WHITE!! (It is ALIVE!)");
	text1.insertText("Less than 2 WHITE neighbors, or more than 3, and the WHITE");
	text1.insertText("becomes BLACK!! (It is DEAD!)");

	resetButton.set_sprite1("pictures//reset.png");
	resetButton.set_sprite2("pictures//reset.png");

	restoreButton.set_sprite1("pictures//restore.png");
	restoreButton.set_sprite2("pictures//restore.png");

	funButton.set_sprite1("pictures//fun.png");
	funButton.set_sprite2("pictures//fun.png");

	saveButton.set_sprite1("pictures//save.png");
	saveButton.set_sprite2("pictures//save.png");

	loadButton.set_sprite1("pictures//load.png");
	loadButton.set_sprite2("pictures//load.png");

	nextSpeedButton.set_sprite1("pictures//next.png");
	nextSpeedButton.set_sprite2("pictures//next.png");

    prevSpeedButton.set_sprite1("pictures//next.png");
	prevSpeedButton.set_sprite2("pictures//next.png");


	hall1.setButtonCallBack(playButton);
	hall1.setButtonCallBack_Reset(resetButton);
	hall1.setButtonCallBack_Restore(restoreButton);
    hall1.setButtonCallBack_FunPatterns(funButton);
    hall1.setButtonCallBack_SaveFile(saveButton);
	hall1.setButtonCallBack_LoadFile(loadButton);
    hall1.setButtonCallBack_NextSpeed(prevSpeedButton);
    hall1.setButtonCallBack_NextSpeed(nextSpeedButton);
    hall1.setGlobalTimer(timer);


	gameMainScreen.insertComponent(&hall1);
	gameMainScreen.insertComponent(&playButton);
	gameMainScreen.insertComponent(&resetButton);
	gameMainScreen.insertComponent(&restoreButton);
	gameMainScreen.insertComponent(&funButton);
	gameMainScreen.insertComponent(&saveButton);
	gameMainScreen.insertComponent(&loadButton);
	//gameMainScreen.insertComponent(&prevSpeedButton);
	gameMainScreen.insertComponent(&nextSpeedButton);
	gameMainScreen.insertComponent(&text1);

	// Game loop
	while (running) {
		ALLEGRO_EVENT event;
		ALLEGRO_TIMEOUT timeout;

		// Initialize timeout
		al_init_timeout(&timeout, 0.06);

		// Fetch the event (if one exists)
		bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);

		// Handle the event
		if (get_event) {
			switch (event.type) {
				case ALLEGRO_EVENT_TIMER:
					redraw = true;
					break;
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					running = false;
					break;
				default:
					break;
			}
		}
		gameMainScreen.setEvents(&event);

		// Check if we need to redraw
		if (redraw && al_is_event_queue_empty(event_queue)) {
			al_clear_to_color(al_map_rgb(0, 0, 0));
			gameMainScreen.update();
			al_flip_display();
			redraw = false;
		}

	}

	// Clean up
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
