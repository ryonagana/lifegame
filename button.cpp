#include <button.h>


myButton::myButton(int x, int y, int sizeX, int sizeY){
	x0 = x;
	y0 = y;
	sizeX0 = sizeX;
	sizeY0 = sizeY;
	pressed = false;
	load_sprites();
}

void myButton::toogle(){
		if(pressed){
			pressed = false;
		}else{
			pressed = true;
		}

		for(int i = 0;i<CallBackList.size();i++){
			ObjectCallBack obj1;
			obj1.object = CallBackList[i].object;
			obj1.func = CallBackList[i].func;
			(obj1.object->*obj1.func)(pressed);
		}
}

void myButton::mouse_event_input(ALLEGRO_EVENT *ev){
	ALLEGRO_MOUSE_STATE state;

	if(ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
		al_get_mouse_state(&state);
		if (state.buttons & 1) {
			/* Primary (e.g. left) mouse button is held. */
			//printf("KKKK Mouse position: (%d, %d)\n", state.x, state.y);
			if((state.x >= x0)&&(state.x <= x0+sizeX0)){
				if((state.y >= y0)&&(state.y <= y0+sizeX0)){
					toogle();
				}
			}
		}
	}
}

void myButton::registerCallBack(myButtonCallBack* object, funcCallBack f1){
	ObjectCallBack obj1;
	obj1.object = object;
	obj1.func = f1;
	CallBackList.push_back(obj1);
}

void myButton::update(){
	draw_sprites();
}

void myButton::load_sprites()
{
   picture1 = al_load_bitmap("pictures//play.png");
   if (!picture1){
	   printf("\n\nNAO CARREGOU picture1\n\n");
   }
   picture2 = al_load_bitmap("pictures//stop.png");
   if (!picture2){
	   printf("\n\nNAO CARREGOU picture2\n\n");
   }


}

void myButton::draw_sprites(){
	if(!pressed){
	al_draw_scaled_bitmap(picture1,
		    0,                                 //Source x
			0,								   //Source y
			al_get_bitmap_width(picture1),     //Source Width
			al_get_bitmap_height(picture1),    //Source Height
			x0, 							   //Destination x
			y0, 							   //Destination y
			sizeX0, 						   //Destination Width
			sizeY0, 						   //Destination Height
			0);
	}else{
	al_draw_scaled_bitmap(picture2,
			0,                                 //Source x
			0,								   //Source y
			al_get_bitmap_width(picture2),     //Source Width
			al_get_bitmap_height(picture2),    //Source Height
			x0, 							   //Destination x
			y0, 							   //Destination y
			sizeX0, 						   //Destination Width
			sizeY0, 						   //Destination Height
			0);
	}

}
