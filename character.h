#ifndef __Characters__
#define __Characters__

#include "CollissionManager.h"
#include "Shooter.h"

class Character : public gameObject
{
    void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    void draw(SDL_Renderer *renderer);
    void update();


private:
    bool shoot = false;
    bool up = false;
    bool down = true;
    bool left = false;
    bool right = false;

    int time = 0;
};

#endif