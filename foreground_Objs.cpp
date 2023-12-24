#include "foreground_Objs.h"

void foreground_Objs::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    gameObject::load(x, y, w, h, id, x_s, y_s, background);

    gameObject::foreground_objs.push_back(this);
}

void foreground_Objs::draw(SDL_Renderer *renderer)
{
    gameObject::draw(renderer);
}

void foreground_Objs::update()
{
}

