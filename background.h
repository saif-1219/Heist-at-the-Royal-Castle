#ifndef __Background__
#define __Background__

#include "static_Objs.h"

class Background : public static_Objs
{
    void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0);
    void draw(SDL_Renderer *renderer);
    void update();

};

#endif