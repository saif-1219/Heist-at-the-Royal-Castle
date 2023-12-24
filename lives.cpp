#include "lives.h"

void lives::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    foreground_Objs::load(x, y, w, h, id, x_s, y_s, background);
}

void lives::draw(SDL_Renderer *renderer)
{
    foreground_Objs::draw(renderer);
}

void lives::update()
{
    currFrame = 0;
    if (gameObject::life == 3)
    {
        currRow = 1;
    }
    else if (gameObject::life == 2)
    {
        currRow = 3;
    }
    else if (gameObject::life == 1)
    {
        currRow = 5;
    }
    else if (gameObject::life == 0)
    {
        currRow = 7;
    }
}



void lives::set_velocity(int x, int y)
{
    foreground_Objs::set_velocity(x, y);
}
