#include "enemy.h"

void enemy::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    gameObject::enemy_objs.push_back(this);
    gameObject::load(x, y, w, h, id, x_s, y_s);
}

void enemy::draw(SDL_Renderer *renderer)
{
    gameObject::draw(renderer);
}

void enemy::update()
{
}
