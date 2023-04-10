#include "Menu.h"
#include "config.h"
#include "main.h"

Menu::Menu(gameScreenContext &context) : menuContext(context)
{
    menu_selected = 1;
    selected_x = 0;
    selected_y = 0;
    cursor = nullptr;

    cursor  = al_load_bitmap("pictures//gl.png");

    if(!cursor){
        cursor = al_create_bitmap(32,32);
        al_set_target_bitmap(cursor);
        al_clear_to_color(al_map_rgb(255,255,255));
        al_set_target_backbuffer(display);
    }

}

Menu::~Menu()
{

}



void Menu::addSingleButton(std::string name, std::string text)
{

    MenuOptionPtr opt = std::make_shared<MenuOption>();

    opt->button.setTextButton(true);
    opt->button.insertText(text);
    opt->text = text;
    opt->name = name;

   m_menu_options.push_back(std::move(opt));
   menuContext.insertComponent(&m_menu_options.back()->button);

    /*

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
    */

}

void Menu::menuFunc(bool status)
{
    printf("status %d", status);
}

void Menu::setMenuOffset(int x, int y, int height_offset)
{

    this->x = x;
    this->y = y;
    this->height_offset = height_offset;
    int count = 1;

    for(auto& m : m_menu_options){
        int text_width = al_get_text_width(m->button.getFont(), m->text.c_str()) + 2;
        m->button.setInfo(x, y + (count + height_offset) * count,text_width, m->button.getFontSize());
        count++;
    }




}

void Menu::setMenuOptionFont(const std::string filepath, int size, int flags)
{
    for(auto& m : m_menu_options){
        m->button.setTextFont(filepath,size,flags);
    }
}

void Menu::setMenuOptionFont(ALLEGRO_FONT *font)
{
    if(!font){
        for(auto& m : m_menu_options){
            m->button.setTextFont(al_create_builtin_font());
        }
        return;
    }

    for(auto& m : m_menu_options){
            m->button.setTextFont(font);
    }
    return;
}

void Menu::MoveMenuUp()
{
    if(static_cast<size_t>(menu_selected) < 1){
        menu_selected = m_menu_options.size();
        return;
    }

    menu_selected--;
}

void Menu::MoveMenuDown()
{
    if(static_cast<size_t>(menu_selected) > m_menu_options.size()-1){
        menu_selected = 1;
        return;
    }


    menu_selected++;
}

void Menu::DrawMenuSelected()
{

    al_draw_scaled_rotated_bitmap(cursor,
                                  al_get_bitmap_width(cursor)/2,
                                  al_get_bitmap_height(cursor)/2,
                                  this->x - 50,
                                  (this->y + this->height_offset) * menu_selected,
                                  0.3f,0.3f,0.0,0
                                  );
}





