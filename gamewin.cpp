#include "gamewin.h"

void gamewin::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    gameObject::win_state_objs.push_back(this);
    gameObject::load(x, y, w, h, id, x_s, y_s);
}

void gamewin::draw(SDL_Renderer *renderer)
{
    gameObject::draw(renderer);
}

void gamewin::update()
{
}