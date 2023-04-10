#ifndef MENU_H
#define MENU_H
#include <string>
#include <memory>
#include <array>
#include <vector>
#include <algorithm>
#include <map>
#include <allegro5/allegro.h>
#include <list>

#include "gameScreenContext.h"
#include "bigTextLabel.h"
#include "button.h"


#include "myButtonCallback.h"

using myButtonPtr = std::shared_ptr<myButton>;

class Menu : public myButtonCallback {

public:

    struct MenuOption {
        std::string text;
        std::string name;
        myButton button;
    };

    using MenuOptionPtr = std::shared_ptr<MenuOption>;

    Menu(gameScreenContext& context);
    void addSingleButton(std::string name, std::string text);

    void menuFunc(bool status);

    virtual void FuncCallBack(bool status){
        menuFunc(status);
        printf("apertou virtual funccallback\n");
    }

    void setMenuOffset(int x, int y, int height_offset = 0);
    void setMenuOptionFont(const std::string filepath, int size, int flags);
    void setMenuOptionFont(ALLEGRO_FONT* font);
private:
    int y;
    int x;
    int height_offset;

    gameScreenContext& menuContext;
    //std::vector<std::unique_ptr<MenuOption>> menu_options;
    //std::map<std::string, myButtonPtr> m_menu_options;
    std::list<MenuOptionPtr> m_menu_options;


};

#endif // MENU_H
