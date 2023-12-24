#include "background.h"

void Background::load(int x, int y, int w, int h, std::string id, int x_s, int y_s)
{
    static_Objs::load(x, y, w, h, id, x_s, y_s); //only one functin being taken from parent class
}

void Background::draw(SDL_Renderer *renderer)
{
    static_Objs::draw(renderer);  //inherited from static_Objs class
}

void Background::update()
{
}