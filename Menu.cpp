#include "Menu.h"

Menu::Menu(gameScreenContext &context) : menuContext(context)
{

    this->menu_font_size = 40;
    this->menu_margin_y = 25;

}

void Menu::addMenu(const std::vector<MenuOption> options)
{
    (void) options;

}

void Menu::addSingleMenu(const std::string name, void (*callback_menu)())
{

    std::unique_ptr<MenuOption> o = std::make_unique<MenuOption>();

    /*MenuOption o;

    menu_options.push_back(o);

    */
    o->menu_name = name;
    o->callback_menu = callback_menu;

    o->button.setTextButton(true);
    o->button.setTextFont("fonts//Game Of Squids.ttf",22,0);
    o->button.X(menuContext.getScreenW()/2);
    o->button.Y(o->button.Y() + this->menu_margin_y * menu_options.size() +  menuContext.getScreenH() / 2 - 100 );

    o->button.insertText(o->menu_name);

    menu_options.push_back(std::move(o));



    menuContext.insertComponent(&menu_options.back().get()->button);

}

void Menu::Update()
{
     for(auto& opt  : menu_options){
         opt.get()->button.X(100);
         opt->button.update();
     }
}

void Menu::Draw()
{

    if(menu_options.size() <= 0) return;





    for(auto& opt  : menu_options){
        static int bottom = 0;


        //al_get_text_dimensions(opt.get()->button.)

        opt->button.X(menuContext.getScreenW()/2 - opt->button.getButtontextWidth());
        opt->button.Y(bottom);
        bottom += this->menu_margin_y;
    }




}

