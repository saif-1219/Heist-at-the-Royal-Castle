#include "Enemy_troll.h"

void Enemy_troll::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    enemy::load(x, y, w, h, id, x_s, y_s);
}

void Enemy_troll::draw(SDL_Renderer *renderer)
{
    enemy::draw(renderer);
}

void Enemy_troll::update()
{
    currFrame = int(((SDL_GetTicks() / 300) % 5));

    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_RIGHT)))
    {
        if ((!TheCollissionManager::Instance()->collides_with_right(gameObject::player_objs, gameObject::objects, 0)))
        {
            if (move_x < 2149 && move_x > 783)
            {
                x_pos -= 1;
            }
        }
    }

    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_LEFT)))
    {
        if (!TheCollissionManager::Instance()->collides_with_left(gameObject::player_objs, gameObject::objects, 0))
        {
            if (move_x < 2149 && move_x > 783)
            {
                x_pos += 1;
            }
        }
    }
    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_UP)))
    {
        if (!TheCollissionManager::Instance()->collides_with_bottom(gameObject::player_objs, gameObject::objects, 0))
        {
            if (move_y < 1152 && move_y > 384)
            {
                y_pos += 1;
            }
        }
    }
    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_DOWN)))
    {
        if (!TheCollissionManager::Instance()->collides_with_top(gameObject::player_objs, gameObject::objects, 0))
        {
            if (move_y < 1152 && move_y > 384)
            {
                y_pos -= 1;
            }
        }
    }
    if (counter == 0)
    {
        moving_right = true;
        moving_left = false;
    }
    if (counter == 100)
    {
        moving_right = false;
        moving_left = true;
    }
    if (moving_right)
    {
        x_pos += 1;
        counter += 1;
    }
    if (moving_left)
    {
        x_pos -= 1;
        counter -= 1;
    }
    int char_x = gameObject::player_objs[0]->get_x();
    int char_y = gameObject::player_objs[0]->get_y();
    int i = char_x - x_pos;
    int j = char_y - y_pos;
    double distance = sqrt((i * i) + (j * j));
    int x = round((i / distance) * 4);
    int y = round((j / distance) * 4);
    int curr_time = SDL_GetTicks();
    if (TheCollissionManager::Instance()->collides_with_buffer(gameObject::player_objs, this, 400))
    {
        if (curr_time - time >= 3000)
        {
            TheShooter::Instance()->enemy_shoot(this, x, y);
            time = curr_time;
        }
    }
}

