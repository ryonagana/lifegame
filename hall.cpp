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

	QuadradosListBackup = new Quadrado*[numeroX];
	for(int i = 0;i<numeroX;i++){
		QuadradosListBackup[i] = new Quadrado[numeroY];
	}

	text_font = al_create_builtin_font();
	play = false;

	buttonReset = nullptr;
	buttonRestore = nullptr;
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

void hall::draw_text(){
	//int number = contNeighbors(9, 19);
    al_draw_textf(text_font,al_map_rgb(255,255,255), x0, y0 - 25, 0, "HALL");
    //al_draw_textf(text_font,al_map_rgb(255,255,255), x0, y0 - 15, 0, "Number of Neighbors: %d", number);
}

void hall::resetAll(bool){
	if(!play){
		for(int i = 0;i<numero_x;i++){
			for(int j = 0;j<numero_y;j++){
				QuadradosList[i][j].checked = false;
			}
		}
	}
}

void hall::makeScreenBackup(){
	for(int i = 0;i<numero_x;i++){
		for(int j = 0;j<numero_y;j++){
			QuadradosListBackup[i][j].checked = QuadradosList[i][j].checked;
		}
	}
}

void hall::restoreScreenBackup(bool){
	if(!play){
		for(int i = 0;i<numero_x;i++){
			for(int j = 0;j<numero_y;j++){
				QuadradosList[i][j].checked = QuadradosListBackup[i][j].checked;
			}
		}
	}
}

void hall::setButtonCallBack_Reset(myButton &b1){
	buttonReset = &b1;
	funcCallBack f1 = &myButtonCallBack::resetAll;
	b1.registerCallBack(this, f1);
}

void hall::setButtonCallBack_Restore(myButton &b1){
	buttonRestore = &b1;
	funcCallBack f1 = &myButtonCallBack::restoreScreenBackup;
	b1.registerCallBack(this, f1);
}

void hall::CreateAndKillLife(){
	if(play){
		for(int i = 0;i<numero_x;i++){
			for(int j = 0;j<numero_y;j++){
				QuadradosList[i][j].checkNeighbors();
			}
		}
	}
}

void hall::update(){
	draw_line();
	draw_text();
	contAllNeighbors();
	CreateAndKillLife();
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

int hall::contNeighbors(int x, int y){
	int count = 0;

	if(x > 0){
		if(QuadradosList[x-1][y].checked){
			count++;
		}
		if((y > 0)&&(QuadradosList[x-1][y-1].checked)){
			count++;
		}
		if((y < numero_y-1)&&(QuadradosList[x-1][y+1].checked)){
			count++;
		}
	}

	if(x < numero_x-1){
		if(QuadradosList[x+1][y].checked){
			count++;
		}
		if((y > 0)&&(QuadradosList[x+1][y-1].checked)){
			count++;
		}
		if((y < numero_y-1)&&(QuadradosList[x+1][y+1].checked)){
			count++;
		}
	}

	if(y > 0){
		if(QuadradosList[x][y-1].checked){
			count++;
		}
	}

	if(y < numero_y-1){
		if(QuadradosList[x][y+1].checked){
			count++;
		}
	}

	return count;
}

void hall::contAllNeighbors(){
	for(int i = 0;i<numero_x;i++){
		for(int j = 0;j<numero_y;j++){
			QuadradosList[i][j].number_of_neighbors = contNeighbors(i,j);
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
			if(!play){
				Position Q1 = get_Position(state.x, state.y);
				if((Q1.x >= 0)&&(Q1.y >= 0)){
					QuadradosList[Q1.x][Q1.y].toogle();
				}
			}
		}
	}
}

void hall::checkQuadrado(int x, int y, bool check){
	QuadradosList[x][y].checked = check;
}

void hall::FuncCallBack(bool pressed){
	buttonReset->setVisible(!pressed);
	buttonRestore->setVisible(!pressed);

	if(pressed == true)makeScreenBackup();
	play = pressed;
}

void hall::setButtonCallBack(myButton &b1){
	funcCallBack f1 = &myButtonCallBack::FuncCallBack;
	b1.registerCallBack(this, f1);
}
