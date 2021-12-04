#include "hall.h"

hall::hall(int x, int y, int sizeJ, int numeroX, int numeroY){
	x0 = x;
	y0 = y;
	size = sizeJ;
	numero_x = numeroX;
	numero_y = numeroY;

	QuadradosList = new Quadrado*[numeroX];
	for(int i = 0;i<numeroX;i++){
		QuadradosList[i] = new Quadrado[numeroY];
	}

	setQuadradoInf();
}

hall::~hall(){

}

void hall::draw_line(){
   ALLEGRO_COLOR color;
   color = al_map_rgb_f(1.0, 1.0, 1.0);
   int x = x0;
   int y = y0;
   int length = numero_x*size;
   int height = numero_y*size;

   while(y <= y0+height){
	   al_draw_line(x, y, x+length, y, color, 0);
	   y = y + size;
   }

   y = y0;
   while(x <= x0+length){
   	   al_draw_line(x, y, x, y+height, color, 0);
   	   x = x + size;
    }
}

void hall::update(){
	draw_line();

	for(int i = 0;i<numero_x;i++){
		for(int j = 0;j<numero_y;j++){
			//QuadradosList[i][j].checkNeighbors();
			QuadradosList[i][j].draw();
		}
	}
}

void hall::setQuadradoInf(){
	for(int i = 0;i<numero_x;i++){
			for(int j = 0;j<numero_y;j++){
				QuadradosList[i][j].size = size;
				QuadradosList[i][j].x = x0 + size*i;
				QuadradosList[i][j].y = y0 + size*j;
			}
		}
}

Position hall::get_Position(int pos_x, int pos_y){
	Position Q1;
	Q1.x = -1;
	Q1.y = -1;

	if((pos_x < x0)||(pos_y < y0)){
		return Q1;
	}

	if((pos_x > (x0 + size * numero_x))||(pos_y > (y0 + size * numero_y))){
		return Q1;
	}

	int x = pos_x - x0;
	x = x / size;

	int y = pos_y - y0;
	y = y / size;

	Q1.x = x;
	Q1.y = y;
	return Q1;
}

void hall::mouse_event_input(ALLEGRO_EVENT *ev){
	ALLEGRO_MOUSE_STATE state;

	if(ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
		al_get_mouse_state(&state);
		if (state.buttons & 1) {
			/* Primary (e.g. left) mouse button is held. */
			//printf("KKKK Mouse position: (%d, %d)\n", state.x, state.y);
			Position Q1 = get_Position(state.x, state.y);
			if((Q1.x >= 0)&&(Q1.y >= 0)){
				QuadradosList[Q1.x][Q1.y].toogle();
			}
		}
	}
}

void hall::checkQuadrado(int x, int y, bool check){
	QuadradosList[x][y].checked = check;
}

void hall::FuncCallBack(bool pressed){
	printf("\n\nDEU CERTO!!!! %d \n\n", pressed);
}

void hall::setButtonCallBack(myButton &b1){
	funcCallBack f1 = &myButtonCallBack::FuncCallBack;
	b1.registerCallBack(this, f1);
}
