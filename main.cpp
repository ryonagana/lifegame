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

#define SCREEN_W 1500
#define SCREEN_H 900

const float FPS = 60;

enum {
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_FIRE
};
static int keys[6] = {0};

int yellow_x = 0;
int yellow_y = 0;

struct QUADRADO {
    int x;
    int y;
};

void fill_rectangle(int x, int y, ALLEGRO_COLOR color);
void player_input_keyboard(ALLEGRO_EVENT *ev);

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_FONT *text_font = NULL;
ALLEGRO_COLOR color;
ALLEGRO_COLOR white = al_map_rgb_f(1.0, 1.0, 1.0);
ALLEGRO_COLOR red = al_map_rgb_f(1.0, 1.0, 1.0);
ALLEGRO_COLOR blue = al_map_rgb_f(1.0, 1.0, 1.0);
ALLEGRO_COLOR yellow = al_map_rgb_f(1.0, 1.0, 0);
bool running = true;
bool redraw = true;


int size = 100;
int init_hall_x = 50;
int init_hall_y = 150;
int hall_W = SCREEN_W - 50;
int hall_H = SCREEN_H - 50;
int number_x = 33;
int number_y = 88;

QUADRADO get_Position(int pos_x, int pos_y){
	QUADRADO Q1;

	int x = pos_x - init_hall_x;
	x = x / size;

	int y = pos_y - init_hall_y;
	y = y / size;

	Q1.x = x;
	Q1.y = y;
	return Q1;
}

void fill_position(int pos_x, int pos_y){
	QUADRADO q1 = get_Position(pos_x, pos_y);
	fill_rectangle(q1.x, q1.y, white);
}


void calc_number_of_squares(){
	number_x = (hall_W-init_hall_x) / size;
	number_y = (hall_H-init_hall_y) / size;
}


void line_draw(){
   color = al_map_rgb_f(1.0, 1.0, 1.0);
   int x = init_hall_x;
   int y = init_hall_y;
   int length = hall_W-init_hall_x;
   int height = hall_H-init_hall_y;

   while(y <= hall_H){
	   //al_draw_line(x, y, x+length, y, color, 0);
	   y = y + size;
   }

   y = init_hall_y;
   while(x <= hall_W){
   	   //al_draw_line(x, y, x, y+height, color, 0);
   	   x = x + size;
    }
}



void rectangle_draw(int x, int y, ALLEGRO_COLOR color){

	//al_draw_rectangle(x, y, x+100, y+100, color, 20);
	al_draw_filled_rectangle(x, y, x+size, y+size, color);
}

void fill_rectangle(int x, int y, ALLEGRO_COLOR color){
	int pos_x = (x*size)+init_hall_x;
	int pos_y = (y*size)+init_hall_y;
	rectangle_draw(pos_x, pos_y, color);
}

void lifegame_draw(){

    al_draw_textf(text_font,al_map_rgb(255,255,255), init_hall_x, init_hall_y - 100, 0, "Life Game!");
    al_draw_textf(text_font,al_map_rgb(255,255,255), init_hall_x, init_hall_y - 100 + 10, 0, "Numero X: %d", number_x);
    al_draw_textf(text_font,al_map_rgb(255,255,255), init_hall_x, init_hall_y - 100 + 20, 0, "Numero Y: %d", number_y);
    al_draw_textf(text_font,al_map_rgb(255,255,255), init_hall_x, init_hall_y - 100 + 40, 0, "Press SPACE or ESC to Restart!");
}

void player_input_mouse(ALLEGRO_EVENT *ev){

	ALLEGRO_MOUSE_STATE state;

	if(ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
		al_get_mouse_state(&state);
		if (state.buttons & 1) {
			/* Primary (e.g. left) mouse button is held. */
			//printf("Mouse position: (%d, %d)\n", state.x, state.y);
			QUADRADO q1 = get_Position(state.x, state.y);
			yellow_x = q1.x;
			yellow_y = q1.y;
		}
	}
}

void player_input_keyboard(ALLEGRO_EVENT *ev){


        if(ev->type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev->keyboard.keycode == ALLEGRO_KEY_W){
                keys[KEY_UP] = 1;
            }
             if(ev->keyboard.keycode == ALLEGRO_KEY_S){
                keys[KEY_DOWN] = 1;
            }

            if(ev->keyboard.keycode == ALLEGRO_KEY_A){
                keys[KEY_LEFT] = 1;
            }

            if(ev->keyboard.keycode == ALLEGRO_KEY_D){
                keys[KEY_RIGHT] = 1;
            }

            if(ev->keyboard.keycode == ALLEGRO_KEY_SPACE || ev->keyboard.keycode == ALLEGRO_KEY_RCTRL){
                keys[KEY_FIRE] = 1;
            }
        }

        if(ev->type == ALLEGRO_EVENT_KEY_UP){
            if(ev->keyboard.keycode == ALLEGRO_KEY_W){
                keys[KEY_UP] = 0;
            }
             if(ev->keyboard.keycode == ALLEGRO_KEY_S){
                keys[KEY_DOWN] = 0;
            }

            if(ev->keyboard.keycode == ALLEGRO_KEY_A){
                keys[KEY_LEFT] = 0;
            }

            if(ev->keyboard.keycode == ALLEGRO_KEY_D){
                keys[KEY_RIGHT] = 0;
            }

            if(ev->keyboard.keycode == ALLEGRO_KEY_SPACE||ev->keyboard.keycode == ALLEGRO_KEY_RCTRL){
                keys[KEY_FIRE] = 0;
            }

        }
}

int init_allegro(void)
{
		// Initialize allegro
		if (!al_init()) {
			fprintf(stderr, "Failed to initialize allegro.\n");
			return 1;
		}

		al_init_image_addon();

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
		calc_number_of_squares();

		return 1;

		error_critical:
		    al_uninstall_system();
		    fprintf(stdout, "Error Critical!");
		    return 0;

}

void update(){
	if(keys[KEY_UP]){
		if(yellow_y > 0){
			yellow_y--;
		}
	}

	if(keys[KEY_DOWN]){
		if(yellow_y < number_y-1){
				yellow_y++;
		}
	}

	if(keys[KEY_LEFT]){
		if(yellow_x > 0){
			yellow_x--;
		}
	}

	if(keys[KEY_RIGHT]){
		if(yellow_x < number_x-1){
			yellow_x++;
		}
	}
}



int main(int argc, char *argv[])
{
	init_allegro();
	//hall obj1(50, 150, 100, 8, 2);
	hall obj2(50, 150, 20, 70, 35);
	myButton playButton(300, 0, 100, 100);
	myButton resetButton(450, 0, 100, 100);
	resetButton.set_sprite1("pictures//reset.png");
	resetButton.set_sprite2("pictures//reset.png");

	obj2.setButtonCallBack(playButton);
	obj2.setButtonCallBack_Reset(resetButton);
	text_font = al_create_builtin_font();



	// Game loop
	while (running) {
		ALLEGRO_EVENT event;
		ALLEGRO_TIMEOUT timeout;

		// Initialize timeout
		al_init_timeout(&timeout, 0.06);

		// Fetch the event (if one exists)
		bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
		//bool get_event = false;
		//al_wait_for_event(event_queue, &event);




		// Handle the event
		if (get_event) {
			switch (event.type) {
				case ALLEGRO_EVENT_TIMER:
					redraw = true;
					update();
					break;
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					running = false;
					break;
				default:
					//fprintf(stderr, "Unsupported event received: %d\n", event.type);
					break;
			}
		}
		player_input_keyboard(&event);
		player_input_mouse(&event);
		//obj1.mouse_event_input(&event);
		obj2.mouse_event_input(&event);
		playButton.mouse_event_input(&event);
		resetButton.mouse_event_input(&event);

		//update();
		// Check if we need to redraw
		if (redraw && al_is_event_queue_empty(event_queue)) {
			// Redraw
			al_clear_to_color(al_map_rgb(0, 0, 0));
			line_draw();
			//fill_rectangle(0, 0, white);
			//fill_rectangle(number_x-1, 0, white);
			//fill_rectangle(0, number_y-1, white);
			//fill_rectangle(number_x-1, number_y-1, white);
			//fill_position(249, 350);
			//fill_rectangle(yellow_x, yellow_y, yellow);
			lifegame_draw();
			//obj1.update();
			obj2.update();
			resetButton.update();
			playButton.update();
			al_flip_display();
			redraw = false;
		}
	}

	// Clean up
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
