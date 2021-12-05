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
#include "button.h"
#include "classCallBack.h"


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
	int number_of_neighbors;
	ALLEGRO_COLOR white = al_map_rgb_f(1.0, 1.0, 1.0);
	Quadrado(){
		checked = false;
		x = 0;
		y = 0;
		size = 50;
		number_of_neighbors = 0;
	}

	void checkNeighbors(){
		if(!checked){
			if(number_of_neighbors == 3) toogle();
		}else{
			if((number_of_neighbors < 2)||(number_of_neighbors > 3)) toogle();
		}
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

class hall: public myButtonCallBack{
private:
	int x0;
	int y0;
	int size;
	int numero_x;
	int numero_y;
	Quadrado** QuadradosList;
	Quadrado** QuadradosListBackup;

	ALLEGRO_FONT *text_font = NULL;
	myButton* buttonReset;
	myButton* buttonRestore;
	myButton* buttonFunPatterns;

	bool play; //If true game is playing if false it is the development fase.

public:
	hall(int x, int y, int sizeJ, int numeroX, int numeroY);
	~hall();
	void draw_line();
	void draw_text();
	void resetAll(bool);
	void makeScreenBackup();
	void restoreScreenBackup(bool);
	void loadFunPatterns(bool);
	void update();
	void checkQuadrado(int x, int y, bool check);
	void setQuadradoInf();
	void mouse_event_input(ALLEGRO_EVENT *ev);
	Position get_Position(int pos_x, int pos_y);
	void setButtonCallBack(myButton &b1);
	void setButtonCallBack_Reset(myButton &b1);
	void setButtonCallBack_Restore(myButton &b1);
	void setButtonCallBack_FunPatterns(myButton &b1);
	int contNeighbors(int x, int y);
	void contAllNeighbors();
	void CreateAndKillLife();
	void FuncCallBack(bool);

};

#endif
