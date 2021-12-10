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
#include "interfaceComponent.h"
#include "button.h"
#include "bigTextLabel.h"
#include "classCallBack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



enum {
	SPEED_NORMAL,
	SPEED_SLOW1,
	SPEED_SLOW2,
	SPEED_SLOW3,
	SPEED_SLOWER,
	SPEED_STOPPED,
    NUMBER_OF_SPEEDS
};

typedef struct Position {
    int x;
    int y;
}Position;

typedef struct EVOLUTION_SPEED {
    int div;
    float speed;
    int type;
}EVOLUTION_SPEED;

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

class hall: public interfaceComponent, myButtonCallBack{
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
	myButton* buttonSaveFile;
	myButton* buttonLoadFile;

	bool play; //If true game is playing if false it is the development fase.
	int generationNumber;
	float evolution_speed;
	int actual_speed;

public:

	EVOLUTION_SPEED ev_speed[NUMBER_OF_SPEEDS] = {
			{1,1.0, SPEED_NORMAL},
			{20,0.75, SPEED_SLOW1},
			{40,0.50, SPEED_SLOW2},
			{60,0.25, SPEED_SLOW3},
			{80,0.10, SPEED_SLOWER},
		    {120,0.00, SPEED_STOPPED}// This one will not be 120 it will stop.
	};

	hall(int x, int y, int sizeJ, int numeroX, int numeroY);
	~hall();
	void draw_line();
	void draw_text();
	void makeScreenBackup();
	void update();
	void checkQuadrado(int x, int y, bool check);
	void setQuadradoInf();
	void setEvents(ALLEGRO_EVENT *ev);
	void mouse_event_input(ALLEGRO_EVENT *ev);
	int saveToFile();
	int readFile();
	Position get_Position(int pos_x, int pos_y);
	void setTextGenerations(bigTextLabel<int> &t1);
	int contNeighbors(int x, int y);
	void contAllNeighbors();
	void CreateAndKillLife();

	//CallBack Register Functions
	void setButtonCallBack(myButton &b1);
	void setButtonCallBack_Reset(myButton &b1);
	void setButtonCallBack_Restore(myButton &b1);
	void setButtonCallBack_FunPatterns(myButton &b1);
	void setButtonCallBack_SaveFile(myButton &b1);
	void setButtonCallBack_LoadFile(myButton &b1);
	void setButtonCallBack_NextSpeed(myButton &b1);
	void setButtonCallBack_PrevSpeed(myButton &b1);
	//CallBack Pointer Functions
	void restoreScreenBackup(bool);
	void loadFunPatterns(bool);
	void FuncCallBack(bool);
	void resetAll(bool);
	void saveFile(bool);
	void loadFile(bool);
	void NextSpeed(bool) override;
	void PrevSpeed(bool) override;

};

#endif
