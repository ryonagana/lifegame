#ifndef MENUHALL_H
#define MENUHALL_H

#include "gameScreenContext.h"
#include "interfaceComponent.h"
#include "Menu.h"
#include <memory>

class MenuHall  {

public:
    MenuHall(gameScreenContext &context);
    ~MenuHall(){}

    void setConfig(Config *config);
    void update(ALLEGRO_EVENT *ev);
    void draw();

private:
    gameScreenContext &m_context;
    std::unique_ptr<Menu> m_menu_ptr;
    std::unique_ptr<Config> m_config;


};

#endif // MENUHALL_H
