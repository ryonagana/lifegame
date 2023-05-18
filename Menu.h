#ifndef MENU_H
#define MENU_H
#include <string>
#include <memory>
#include <array>
#include <vector>
#include <algorithm>
#include <allegro5/allegro.h>
#include <list>

#include "gameScreenContext.h"
#include "bigTextLabel.h"
#include "button.h"


#include "myButtonCallback.h"

class Menu {

public:

    enum class MenuOptionId: int {
        START_GAME=1,
        QUIT
    };

    struct MenuOption :  public myButtonCallback {
        std::string text;
        std::string name;
        myButton button;
        gameScreenContext& context;
        void (*callback_callee)(bool, gameScreenContext&);

        // myButtonCallback interface
    public:
        MenuOption(gameScreenContext& ctx) : context(ctx){

        }
        virtual void FuncCallBack(bool status) {
            callback_callee(status, context);
        }
    };

    using MenuOptionPtr = std::shared_ptr<MenuOption>;


    Menu(gameScreenContext& context);
    ~Menu();
    void addSingleButton(std::string name, std::string text, void (*callback_callee)(bool, gameScreenContext &) = nullptr);


    void setMenuOffset(int x, int y, int height_offset = 0);
    void setMenuOptionFont(const std::string filepath, int size, int flags);
    void setMenuOptionFont(ALLEGRO_FONT* font);

    void moveMenuUp();
    void moveMenuDown();

    void drawMenuSelected();
    void drawTitle();

    void updateMenu();
    void processMenuEvents(ALLEGRO_EVENT& e, Menu& menu);

    static void Menu_StartButtonClick(bool status,  gameScreenContext& context);
    static void Menu_QuitButtonClick(bool status,  gameScreenContext& context);

private:
    int y;
    int x;
    int width_offset;
    int height_offset;

    int menu_selected;
    int selected_x;
    int selected_y;

    ALLEGRO_BITMAP *cursor;

    gameScreenContext& menuContext;
    std::list<Menu::MenuOptionPtr> m_menu_options;
    MenuOptionId menu_chosen;


};

#endif // MENU_H
