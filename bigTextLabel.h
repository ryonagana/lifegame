#ifndef BIGTEXTLABEL_CPP
#define BIGTEXTLABEL_CPP

#include "interfaceComponent.h"
#include <vector>

class bigTestLabel: public interfaceComponent{
private:
	int x0;
	int y0;
	ALLEGRO_COLOR white;
	ALLEGRO_COLOR red;
	ALLEGRO_COLOR blue;
	ALLEGRO_COLOR yellow;
	ALLEGRO_FONT *text_font = nullptr;
	std::vector<const char*> listOfText;

public:
	bigTestLabel();
	bigTestLabel(int x, int y);
	void insertText(const char* t1);
	void setEvents(ALLEGRO_EVENT *ev);
	void update();
};

#endif
