#include "keys.h"

void keys::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    foreground_Objs::load(x, y, w, h, id, x_s, y_s, background);
}

void keys::draw(SDL_Renderer *renderer)
{
    foreground_Objs::draw(renderer);
}

void keys::update()
{
    currFrame = 0;
    if (gameObject::keys == 1)
    {
        currRow = 1;
    }
    else if (gameObject::keys == 2)
    {
        currRow = 3;
    }
    else if (gameObject::keys == 3)
    {
        currRow = 5;
    }
    else if (gameObject::keys == 0)
    {
        currRow = 7;
    }
    else if (gameObject::keys == 4)
    {
        gameObject::state = 3;
    }
}



void keys::set_velocity(int x, int y)
{
    foreground_Objs::set_velocity(x, y);
}
