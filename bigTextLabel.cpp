#include "bigTextLabel.h"

bigTestLabel::bigTestLabel(){
	x0 = 0;
	y0 = 0;
	white = al_map_rgb_f(1.0, 1.0, 1.0);
	red = al_map_rgb_f(1.0, 1.0, 1.0);
	blue = al_map_rgb_f(1.0, 1.0, 1.0);
	yellow = al_map_rgb_f(1.0, 1.0, 0);
	text_font = al_create_builtin_font();
}

bigTestLabel::bigTestLabel(int x, int y){
	x0 = x;
	y0 = y;
	white = al_map_rgb_f(1.0, 1.0, 1.0);
	red = al_map_rgb_f(1.0, 1.0, 1.0);
	blue = al_map_rgb_f(1.0, 1.0, 1.0);
	yellow = al_map_rgb_f(1.0, 1.0, 0);
	text_font = al_create_builtin_font();
}

void bigTestLabel::insertText(const char* t1){
	listOfText.push_back(t1);
}

void bigTestLabel::setEvents(ALLEGRO_EVENT *ev){

}

void bigTestLabel::update(){
	int position_x = x0;
	int position_y = y0;
	ALLEGRO_COLOR white = al_map_rgb_f(1.0, 1.0, 1.0);

	for(size_t i = 0;i<listOfText.size();i++){
		al_draw_textf(text_font, white, position_x, position_y, 0, listOfText[i]);
		position_y = position_y + 10;
	}
}
