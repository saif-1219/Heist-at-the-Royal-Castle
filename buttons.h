#ifndef BUTTON_H
#define BUTTON_H

#include "gameObj.h"

class buttons : public gameObject
{
public:
    // SDL_Rect rect;
    void draw(SDL_Renderer *renderer);
    void load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background);
    void update();
    bool isClicked(int mouseX, int mouseY);
    // SDL_Rect rect = {x_pos, y_pos, width, height};
};

#endif // BUTTON_H