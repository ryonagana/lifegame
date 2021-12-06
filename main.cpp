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

#define SCREEN_W 1300
#define SCREEN_H 700

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
		    goto error_critical;
		}

		if (!al_install_keyboard()) {
		    goto error_critical;
		}

		if (!al_install_mouse()) {
		    goto error_critical;
		}

		// Initialize the timer
		timer = al_create_timer(1.0 / FPS);
		if (!timer) {
			fprintf(stderr, "Failed to create timer.\n");
			return 1;
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

		error_critical:
		    al_uninstall_system();
		    fprintf(stdout, "Error Critical!");
		    return 0;
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
	myButton playButton(650, 40, 100, 100);
	myButton resetButton(760, 40, 100, 100);
	myButton restoreButton(900, 40, 100, 100);
	myButton funButton(1040, 40, 100, 100);
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

	hall1.setButtonCallBack(playButton);
	hall1.setButtonCallBack_Reset(resetButton);
	hall1.setButtonCallBack_Restore(restoreButton);
    hall1.setButtonCallBack_FunPatterns(funButton);

	gameMainScreen.insertComponent(&hall1);
	gameMainScreen.insertComponent(&playButton);
	gameMainScreen.insertComponent(&resetButton);
	gameMainScreen.insertComponent(&restoreButton);
	gameMainScreen.insertComponent(&funButton);
	gameMainScreen.insertComponent(&text1);

	//al_resize_display(display, 1600, 1000); //resize screen

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
