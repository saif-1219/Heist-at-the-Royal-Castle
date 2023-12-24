#ifndef __gameObject__
#define __gameObject__

#include <SDL.h>
#include <vector>
#include <string>
#include <array>
#include <SDL_image.h>
#include <iostream>
#include "InputHandler.h"
#include "TextureManager.h"

class gameObject
{
public:
    virtual void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();

    virtual void remove_from_vector(std::vector<gameObject *> &vec, gameObject *obj);
    virtual bool isClicked(int mouseX, int mouseY);
    int get_x();
    int get_y();
    int get_width();
    int get_height();

    void increment_x(int x);
    void increment_y(int y);
    void decrement_x(int x);
    void decrement_y(int y);

    virtual void set_velocity(int x, int y);
    
    friend std::ostream& operator<<(std::ostream& os, const gameObject& obj){
        os << "x_pos: " << obj.x_pos << "\n";
        os << "y_pos: " << obj.y_pos << "\n";
        os << "width: " << obj.width << "\n";
        os << "height: " << obj.height << "\n";
        os << "name: " << obj.name << "\n";
        os << "currFrame: " << obj.currFrame << "\n";
        os << "currRow: " << obj.currRow << "\n";
        os << "velocity_x: " << obj.velocity_x << "\n";
        os << "velocity_y: " << obj.velocity_y << "\n";
        os << "x_sor: " << obj.x_sor << "\n";
        os << "y_sor: " << obj.y_sor << "\n";
    
        return os;
    }

    static std::vector<gameObject *> objects;
    static std::vector<gameObject *> player_objs;
    static std::vector<gameObject *> enemy_objs;
    static std::vector<gameObject *> foreground_objs;
    static std::vector<gameObject *> menu_objects;
    static std::vector<gameObject *> win_state_objs;
    static std::vector<gameObject *> lose_state_objs;
    static std::vector<gameObject *> Collectible_objects;

    static int keys;

    static int move_x;
    static int move_y;

    static int state;

    static int life;

    std::string get_name();

protected:
    std::string name;

    int x_pos;
    int y_pos;

    int x_sor = 0;
    int y_sor = 0;

    int width;
    int height;

    int currFrame;
    int currRow;

    int velocity_x = 0;
    int velocity_y = 0;
};

#endif