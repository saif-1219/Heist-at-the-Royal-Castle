#pragma once

#include "Static_tree.h"
#include "CollissionManager.h"

class Bullet : public Static_tree
{
public:
    virtual void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();
    virtual void set_velocity(int x, int y);

private:
    int velocity_x;
    int velocity_y;
};