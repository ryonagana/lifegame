#ifndef INTERFACECOMPONENT_CPP
#define INTERFACECOMPONENT_CPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <iostream>

class interfaceComponent{
public:
	interfaceComponent(){}
	virtual ~interfaceComponent(){}
	virtual void setEvents(ALLEGRO_EVENT *ev) = 0;
	virtual void update() = 0;
};

#endif
