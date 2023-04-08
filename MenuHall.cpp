#include "MenuHall.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

MenuHall::MenuHall(gameScreenContext &context) : m_context(context)
{
    m_menu_ptr = std::make_unique<Menu>(context);

    m_menu_ptr->addSingleButton("START", m_menu_ptr.get(), &myButtonCallBack::FuncCallBack);
    //m_menu_ptr->addSingleButton("LOAD", m_menu_ptr.get(),  nullptr);
    //m_menu_ptr->addSingleButton("QUIT", m_menu_ptr.get(), nullptr);

}

void MenuHall::setConfig(Config *config)
{
    m_config.reset(config);
}

void MenuHall::update(ALLEGRO_EVENT *ev)
{
    bool fullscreen = false;
    if(m_config)
        fullscreen = m_config->getConfigValue<bool>("game", "fullscreen");


    if(fullscreen){

    }

    m_menu_ptr->Update(ev);
    m_context.update();
    m_context.update_input(ev);
    return;
}

void MenuHall::draw()
{
    m_context.draw();
    return;
}

