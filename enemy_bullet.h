#pragma once

#include "Static_tree.h"
#include "Game.h"

class enemy_bullet : public Static_tree
{
public:
    virtual void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();
    virtual void set_velocity(int x, int y);
};