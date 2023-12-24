#include "enemy_bullet.h"

void enemy_bullet::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    static_Objs::load(x, y, w, h, id, x_s, y_s, background);
}

void enemy_bullet::draw(SDL_Renderer *renderer)
{
    static_Objs::draw(renderer);
}

void enemy_bullet::update()
{
    Static_tree::update();
    currFrame = int(((SDL_GetTicks() / 300) % 4));
    x_pos += velocity_x;
    y_pos += velocity_y;
    if (TheCollissionManager::Instance()->collides(gameObject::objects, this) || (x_pos > 3000) || (x_pos < 0) || (y_pos > 3000) || (y_pos < 0))
    {
        gameObject::remove_from_vector(gameObject::objects, this);
    }
    if (TheCollissionManager::Instance()->collides(gameObject::player_objs, this))
    {
        gameObject::remove_from_vector(gameObject::objects, this);
        gameObject::life--;
        Mix_PlayChannel(-1, Game::lifelost, 0);
    }
}



void enemy_bullet::set_velocity(int x, int y)
{
    velocity_x = x;
    velocity_y = y;
}