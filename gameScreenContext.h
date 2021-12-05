#ifndef GAMESCREENCONTEXT_CPP
#define GAMESCREENCONTEXT_CPP

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
#include <vector>
#include "interfaceComponent.h"
#include "button.h"
#include "hall.h"


class gameScreenContext{
private:
	int x0;
	int y0;
	int screen_W;
	int screen_H;
	std::vector<interfaceComponent*> list_of_components;

public:
	gameScreenContext();
	void setScreenSize(int w, int h);
	void insertComponent(interfaceComponent* c1);
	void setComponents();
	void setEvents(ALLEGRO_EVENT *ev);
	void update();

};

#endif
