#pragma once
#include "foreground_Objs.h"
#include "Game.h"
#include "SDL_mixer.h" // Include SDL_mixer library

class keys : public foreground_Objs
{
public:
    virtual void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();

    virtual void set_velocity(int x, int y);
};