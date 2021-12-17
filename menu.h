#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <memory>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "button.h"
#include "interfaceComponent.h"

typedef struct MENU_ITEM {
    float x;
    float y;
    std::string name;
    bool selected;
    void (*callback_menu_clicked)(bool);
    myButton button;

    MENU_ITEM():
        x(0),
        y(0),
        name(""),
        selected(false)
        {
        }
}MENU_ITEM;


typedef struct MENU {
    std::vector<MENU_ITEM> items;
    int option_start;

    MENU(){
        option_start = 0;
    }

    void addMenuItem(const std::string name, float x, float y,  void (*callback_menu_clicked)(bool)){
        MENU_ITEM item;
        item.x = x;
        item.y = y;
        item.name = name;
        item.selected = false;
        item.callback_menu_clicked = callback_menu_clicked;
        //item->button.set_text(name);
        //item->button.set_font("fonts//Game Of Squids.ttf");

        items.push_back(item);
    }
}MENU;


using MenuPtr = std::shared_ptr<MENU>;

#define MENU_GAP 32

class GameMenu : public interfaceComponent {
public:
    GameMenu();
    bool addMenu(const std::string name, MENU* menu);
    void setActualmenu(const std::string key);
    MENU* getMenu();
    MENU* actualMenu;
    MenuPtr find(const std::string name);

    virtual void start();
    virtual void draw();
    virtual void update();
    virtual void update_input(ALLEGRO_EVENT *e);

    virtual void setGlobalDisplay(ALLEGRO_DISPLAY *dsp);
private:
    std::unordered_map<std::string, MenuPtr> menuMap;
    float cursor_x;
    float cursor_y;
    ALLEGRO_FONT *menu_font;



};

#endif // MENU_H
