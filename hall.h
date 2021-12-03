#ifndef HALL_CPP
#define HALL_CPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <iostream>

struct Position {
    int x;
    int y;
};

class Quadrado{
public:
	bool checked;
	int x;
	int y;
	int size;
	ALLEGRO_COLOR white = al_map_rgb_f(1.0, 1.0, 1.0);
	Quadrado(){
		checked = false;
		x = 0;
		y = 0;
		size = 50;
	}

	void checkNeighbors(){

	}

	void draw(){
		if(checked){
			al_draw_filled_rectangle(x, y, x+size, y+size, white);
		}
	}

	void toogle(){
		if(checked){
			checked = false;
		}else{
			checked = true;
		}
	}
};

class hall{
private:
	int x0;
	int y0;
	int size;
	int numero_x;
	int numero_y;
	Quadrado** QuadradosList;

public:
	hall(int x, int y, int sizeJ, int numeroX, int numeroY);
	void draw_line();
	void update(ALLEGRO_EVENT *ev);
	void checkQuadrado(int x, int y, bool check);
	void setQuadradoInf();
	void mouse_event_input(ALLEGRO_EVENT *ev);
	Position get_Position(int pos_x, int pos_y);

};


#endif
