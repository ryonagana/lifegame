#include "menu.h"


GameMenu::GameMenu() : interfaceComponent(),
    cursor_x(0),
    cursor_y(0)
{
    menu_font = al_create_builtin_font();

}

void GameMenu::start(){
    for(auto& i: actualMenu->items){
        i.button.start();
    }
}

bool GameMenu::addMenu(const std::string name, MENU* menu){
    if(!menu){
        return false;
    }

    menuMap.insert(std::make_pair(name, std::move(menu)));
    actualMenu = menuMap[name].get();


    for(auto i : actualMenu->items){
        i.button.setGlobalDisplay(display);
    }

    return true;
}


void GameMenu::setActualmenu(const std::string key){
    auto f = this->find(key);
    actualMenu = f.get();
}

MENU* GameMenu::getMenu(){
    return actualMenu;
}


MenuPtr GameMenu::find(const std::string name){
    auto f = this->menuMap.find(name);

    if(f == this->menuMap.end()){
        return nullptr;
    }

    return f->second;

}

void GameMenu::draw(){
    for(auto& i : actualMenu->items){
         i.button.draw();
    }
}



void GameMenu::update()
{



}

void GameMenu::update_input(ALLEGRO_EVENT* e)
{
        if(e->type == ALLEGRO_EVENT_KEY_UP){
            if(e->keyboard.keycode == ALLEGRO_KEY_UP || e->keyboard.keycode == ALLEGRO_KEY_W){
                //cursor_x += 32;
            }
        }

        for(auto& i : actualMenu->items){
         i.button.update_input(e);
        }

}


void GameMenu::setGlobalDisplay(ALLEGRO_DISPLAY* dsp)
{
   interfaceComponent::setGlobalDisplay(dsp);
   for(auto& i : this->getMenu()->items){
       i.button.load_sprites();
   }
}
