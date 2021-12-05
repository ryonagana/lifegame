#ifndef BUTTON_CPP
#define BUTTON_CPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include "classCallBack.h"
#include <iostream>
#include <vector>

typedef void (myButtonCallBack::*funcCallBack)(bool);

struct ObjectCallBack{
	myButtonCallBack* object;
	funcCallBack func;
};

class myButton{
private:
	int x0;
	int y0;
	int sizeX0;
	int sizeY0;
	bool pressed;
	ALLEGRO_BITMAP *picture1 = NULL;
	ALLEGRO_BITMAP *picture2 = NULL;
	std::vector<ObjectCallBack> CallBackList;

public:
	myButton(int x, int y, int sizeX, int sizeY);
	void toogle();
	void mouse_event_input(ALLEGRO_EVENT *ev);
	void update();
	void load_sprites();
	void draw_sprites();
	void registerCallBack(myButtonCallBack* object, funcCallBack c1);
	void set_sprite1(const char *filename);
	void set_sprite2(const char *filename);
};


#endif
