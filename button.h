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
#include "interfaceComponent.h"
#include "classCallBack.h"
#include <iostream>
#include <vector>

typedef void (myButtonCallBack::*funcCallBack)(bool);

struct ObjectCallBack{
	myButtonCallBack* object;
	funcCallBack func;
};

class myButton: public interfaceComponent{
private:
	int x0;
	int y0;
	int sizeX0;
	int sizeY0;
	bool pressed;
	bool visible;
	bool holdButton; //Hold the button always in the same position. Always true or always false. See "alwaysButton"
	bool alwaysButton; // If holdButton = true the button pressed will be kept always in this position.
	ALLEGRO_BITMAP *picture1 = NULL;
	ALLEGRO_BITMAP *picture2 = NULL;
	std::vector<ObjectCallBack> CallBackList;

public:
	myButton(int x, int y, int sizeX, int sizeY);
	myButton();
	void setInfo(int x, int y, int sizeX, int sizeY);
	void setVisible(bool v1);
	void toogle();
	void setPressedAlwaysFalse();
	void setPressedAlwaysTrue();
	void setEvents(ALLEGRO_EVENT *ev);
	void mouse_event_input(ALLEGRO_EVENT *ev);
	void update();
	void load_sprites();
	void draw_sprites();
	void registerCallBack(myButtonCallBack* object, funcCallBack c1);
	void set_sprite1(const char *filename);
	void set_sprite2(const char *filename);
};


#endif
