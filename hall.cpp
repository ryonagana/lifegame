#include "hall.h"
#include <cstdio>
#include <cstdlib>

hall::hall(int x, int y, int sizeJ, int numeroX, int numeroY) : interfaceComponent() {
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

	buttonReset = nullptr;
	buttonRestore = nullptr;
	buttonFunPatterns = nullptr;
	buttonSaveFile = nullptr;
	buttonLoadFile = nullptr;

	play = false;
	actual_speed = SPEED_NORMAL;
	evolution_speed = ev_speed[actual_speed].type;
	generationNumber = 0;
}

hall::~hall(){

}

void hall::draw_line(){
   ALLEGRO_COLOR color;
   color = al_map_rgb_f(0.3, 0.3, 0.3);
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
    al_draw_textf(text_font,al_map_rgb(255,255,255), x0, y0 - 35, 0, "HALL");
    al_draw_textf(text_font,al_map_rgb(255,255,255), x0, y0 - 25, 0, "%d X %d", numero_x, numero_y);
    al_draw_textf(text_font,al_map_rgb(255,255,255), x0, y0 - 15, 0, "Evolution Speed: %.2f", ev_speed[actual_speed].speed);

}

void hall::resetAll(bool){
	if(!play){
		generationNumber = 0;
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

void hall::setButtonCallBack_FunPatterns(myButton &b1){
	buttonFunPatterns = &b1;
	funcCallBack f1 = &myButtonCallBack::loadFunPatterns;
	b1.registerCallBack(this, f1);
}

void hall::setButtonCallBack_SaveFile(myButton &b1){
	buttonSaveFile = &b1;
	funcCallBack f1 = &myButtonCallBack::saveFile;
	b1.registerCallBack(this, f1);
}

void hall::setButtonCallBack_LoadFile(myButton &b1){
	buttonLoadFile = &b1;
	funcCallBack f1 = &myButtonCallBack::loadFile;
	b1.registerCallBack(this, f1);
}

void hall::saveFile(bool){
	saveToFile();
}

void hall::loadFile(bool){
	readFile();
}

void hall::CreateAndKillLife(){
	if(play && ev_speed[actual_speed].type != SPEED_STOPPED){
		double CurrentTimer = (al_get_timer_count(this->timer) / ev_speed[actual_speed].div);
        if(CurrentTimer >= evolution_speed){
        	generationNumber++;
        	for(int i = 0;i<numero_x;i++){
                for(int j = 0;j<numero_y;j++){
                    QuadradosList[i][j].checkNeighbors();
                }
            }
            evolution_speed = (al_get_timer_count(this->timer) / ev_speed[actual_speed].div)+ev_speed[actual_speed].speed;
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

void hall::setEvents(ALLEGRO_EVENT *ev){
	mouse_event_input(ev);
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

void hall::loadFunPatterns(bool){
	if(!play){

		//Pattern 1
		int x1 = 106;
		int y1 = 25;
		QuadradosList[x1][y1].checked = true;
		QuadradosList[x1][y1+1].checked = true;
		QuadradosList[x1+1][y1].checked = true;
		QuadradosList[x1+2][y1].checked = true;
		QuadradosList[x1+3][y1].checked = true;
		QuadradosList[x1+4][y1].checked = true;
		QuadradosList[x1+4][y1+1].checked = true;

		//Pattern 2
		int x2 = 100;
		int y2 = 0;
		QuadradosList[x2][y2].checked = true;
		QuadradosList[x2][y2+1].checked = true;
		QuadradosList[x2][y2+2].checked = true;
		QuadradosList[x2+1][y2+2].checked = true;
		QuadradosList[x2+2][y2+1].checked = true;

		//Pattern 3
		int x3 = 74;
		int y3 = 30;
		QuadradosList[x3][y3].checked = true;
		QuadradosList[x3+1][y3].checked = true;
		QuadradosList[x3][y3+1].checked = true;
		QuadradosList[x3+1][y3+1].checked = true;

		//Pattern 4
		int x4 = 24;
		int y4 = 26;
		QuadradosList[x4][y4].checked = true;
		QuadradosList[x4][y4-1].checked = true;
		QuadradosList[x4][y4+1].checked = true;
		QuadradosList[x4+1][y4].checked = true;
		QuadradosList[x4+2][y4].checked = true;
		QuadradosList[x4+3][y4].checked = true;
		QuadradosList[x4+4][y4].checked = true;
	}
}

void hall::FuncCallBack(bool pressed){
	if(pressed)generationNumber = 0;
	buttonReset->setVisible(!pressed);
	buttonRestore->setVisible(!pressed);
	buttonFunPatterns->setVisible(!pressed);
	buttonSaveFile->setVisible(!pressed);
	buttonLoadFile->setVisible(!pressed);

	if(pressed == true)makeScreenBackup();
	play = pressed;
}

void hall::setButtonCallBack(myButton &b1){
	funcCallBack f1 = &myButtonCallBack::FuncCallBack;
	b1.registerCallBack(this, f1);
}

int hall::saveToFile () {
  std::ofstream myfile;
  myfile.open ("SavedGame.txt");
  myfile << numero_x << " " <<  numero_y << "\n";
  for(int i = 0;i<numero_x;i++){
  	for(int j = 0;j<numero_y;j++){
  		myfile << i << " " <<  j << " " << QuadradosList[i][j].checked << "\n";
  	}
  }
  myfile.close();
  return 0;
}

int hall::readFile () {
	std::string line;
	std::ifstream myfile ("SavedGame.txt");
	if (myfile.is_open())
	{
		resetAll(true);
		getline (myfile,line);
		std::stringstream gridInfo(line);
		std::string word0;
		int numX = -1;
		int numY = -1;
		gridInfo >> numX;
		gridInfo >> numY;

		while ( getline (myfile,line) )
	    {
			std::stringstream ss(line);
			std::string word;
			int i = -1;
			int j = -1;
			bool check = false;
			ss >> i;
			ss >> j;
			ss >> check;
			if((i < numero_x)&&(j < numero_y)){
				QuadradosList[i][j].checked = check;
			}
	    }
	    myfile.close();
	}
  return 0;
}

void hall::setButtonCallBack_NextSpeed(myButton &b1){
    funcCallBack cb = &myButtonCallBack::NextSpeed;
    b1.registerCallBack(this,cb);
}

void hall::setButtonCallBack_PrevSpeed(myButton &b1){
    funcCallBack cb = &myButtonCallBack::PrevSpeed;
    b1.registerCallBack(this,cb);
}

void hall::setTextGenerations(bigTextLabel<int> &t1){
	t1.insertText("Generation #%d", &generationNumber);
}

void hall::NextSpeed(bool)
{
	if (actual_speed == SPEED_NORMAL){
		actual_speed = SPEED_STOPPED;//Go back to the stopped speed
	} else{
		actual_speed--;
	}
	this->evolution_speed = (al_get_timer_count(timer) / ev_speed[actual_speed].div);
}

void hall::PrevSpeed(bool) {
	actual_speed++;
	if (actual_speed == NUMBER_OF_SPEEDS) actual_speed = SPEED_NORMAL;//Go back to the normal speed
	this->evolution_speed = (al_get_timer_count(timer) / ev_speed[actual_speed].div);
}
