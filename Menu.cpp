#include "Menu.h"
#include "config.h"


Menu::Menu(gameScreenContext &context) : menuContext(context)
{

    this->menu_font_size = 40;
    this->menu_margin_y = 25;



}

void Menu::addMenu(const std::vector<MenuOption> options)
{
    (void) options;

}

void Menu::addSingleButton(const std::string name,  myButtonCallBack* object, funcCallBack f1)
{

    std::unique_ptr<MenuOption> o = std::make_unique<MenuOption>();

    /*MenuOption o;

    menu_options.push_back(o);


    */
    printf("CRIOU MENU\n");

    o->menu_name = name;
    //o->callback_menu = callback;
    //o->button.registerCallBack
    o->button.registerCallBack(object,f1);
   // o->button.setInfo(menuContext.getScreenW()/2, o->button.Y() + this->menu_margin_y * menu_options.size() +  menuContext.getScreenH() / 2 - 100, 200,200 );
    o->button.setInfo(300,300,100,100);

    o->button.setTextButton(true);
    o->button.setTextFont("fonts//Game Of Squids.ttf",22,0);
    //o->button.X(menuContext.getScreenW()/2);
    //o->button.Y(o->button.Y() + this->menu_margin_y * menu_options.size() +  menuContext.getScreenH() / 2 - 100 );

    o->button.insertText(o->menu_name);
    //o->button.registerCallBack()

    menu_options.push_back(std::move(o));



    menuContext.insertComponent(&menu_options.back().get()->button);

}

void Menu::Update(ALLEGRO_EVENT *event)
{

     for(auto& opt  : menu_options){
         opt.get()->button.X(100);
         opt->button.update();
         opt->button.update_input(event);


     }
}

void Menu::Draw()
{

    if(menu_options.size() <= 0) return;


    for(auto& opt  : menu_options){
        static int bottom = 0;
        opt->button.X(menuContext.getScreenW()/2 - opt->button.getButtontextWidth());
        opt->button.Y(bottom);
        bottom += this->menu_margin_y;
    }




}

void Menu::menuFunc(bool status)
{
        (void)status;
        printf("AAAAAAA\n");
}





