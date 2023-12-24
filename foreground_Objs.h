#pragma once

#include "gameObj.h"

class foreground_Objs : public gameObject
{
public:
    virtual void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();
};