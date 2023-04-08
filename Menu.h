#ifndef MENU_H
#define MENU_H
#include "gameScreenContext.h"
#include "bigTextLabel.h"
#include "button.h"
#include <string>
#include <memory>
#include <array>
#include <vector>
#include <allegro5/allegro.h>
#include "classCallBack.h"


typedef void (*menu_callback)(void);

class Menu : public myButtonCallBack {

public:

    struct MenuOption {
        myButton button;
        std::string menu_name;
        funcCallBack callback_menu;
    };

    Menu(gameScreenContext& context);
    void addMenu(const std::vector<MenuOption> options);
    void addSingleButton(const std::string name, myButtonCallBack *object, funcCallBack f1);
    void Update(ALLEGRO_EVENT *event);
    void Draw();

    void menuFunc(bool status);

    virtual void FuncCallBack(bool status){
        menuFunc(status);
        printf("apertou virtual funccallback\n");
    }

private:
    int menu_font_size;
    int menu_margin_y;

    gameScreenContext& menuContext;
    std::vector<std::unique_ptr<MenuOption>> menu_options;


};

#endif // MENU_H
