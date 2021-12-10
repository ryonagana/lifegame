#include "gameScreenContext.h"

gameScreenContext::gameScreenContext(){
	//x0 = 0;
	//y0 = 0;
	screen_W = 800;
	screen_H = 600;
}

void gameScreenContext::setScreenSize(int w, int h){
	screen_W = w;
	screen_H = h;
}

void gameScreenContext::insertComponent(interfaceComponent* c1){
	list_of_components.push_back(c1);
}

void gameScreenContext::setGlobalTimer(ALLEGRO_TIMER *timer){
	for(size_t i = 0;i<list_of_components.size();i++){
			list_of_components[i]->setGlobalTimer(timer);
	}
}

void gameScreenContext::setComponents(){

}

void gameScreenContext::setEvents(ALLEGRO_EVENT *ev){
	for(size_t i = 0;i<list_of_components.size();i++){
		list_of_components[i]->setEvents(ev);
	}

}

void gameScreenContext::update(){
	for(size_t i = 0;i<list_of_components.size();i++){
		list_of_components[i]->update();
	}
}
