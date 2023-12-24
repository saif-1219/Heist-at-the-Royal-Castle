#pragma once

#include "enemy.h"
#include "Shooter.h"
#include <cmath>

class Enemy_troll : public enemy
{
public:
    virtual void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();


protected:
    bool moving_right = true;
    bool moving_left = false;
    int counter = 50;
    int time = 0;
};