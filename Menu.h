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


class Menu {

public:

    struct MenuOption {
        myButton button;
        std::string menu_name;
        void (*callback_menu)(void);
    };

    Menu(gameScreenContext& context);
    void addMenu(const std::vector<MenuOption> options);
    void addSingleMenu(const std::string name, void (*callback_menu)(void));
    void Update();
    void Draw();


private:
    int menu_font_size;
    int menu_margin_y;

    gameScreenContext& menuContext;
    std::vector<std::unique_ptr<MenuOption>> menu_options;

};

#endif // MENU_H
