#include "character.h"

void Character::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    player_objs.push_back(this);
    gameObject::load(x, y, w, h, id, x_s, y_s, background);
}

void Character::draw(SDL_Renderer *renderer)
{
    gameObject::draw(renderer);
}

void Character::update()
{

    if (x_pos < 0)
    {
        x_pos = 0;
    }
    if (x_pos > 1366 - width)
    {
        x_pos = 1366 - width;
    }
    if (y_pos < 0)
    {
        y_pos = 0;
    }
    if (y_pos > 768 - height)
    {
        y_pos = 768 - height;
    }
    if (move_x < 0)
    {
        move_x = 0;
    }
    if (move_x > 1366 * 2)
    {
        move_x = 1366 * 2;
    }
    if (move_y < 0)
    {
        move_y = 0;
    }
    if (move_y > 768 * 2)
    {
        move_y = 768 * 2;
    }

    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_RIGHT)))
    {
        up = false;
        down = false;
        left = false;
        right = true;

        currRow = 3;
        currFrame = int(((SDL_GetTicks() / 300) % 4));
        if (move_x >= 2149 || move_x <= 783)
        {
            x_pos += 1;
            if (TheCollissionManager::Instance()->collides(gameObject::objects, this))
            {
                x_pos -= 1;
                move_x -= 1;
            }
        }
    }
    else if (TheInputHandler::Instance()->keyDown(SDL_SCANCODE_LEFT))
    {
        up = false;
        down = false;
        left = true;
        right = false;
        currRow = 4;
        currFrame = int(((SDL_GetTicks() / 300) % 4));
        if (move_x <= 783 || move_x >= 2149)
        {
            x_pos -= 1;
            if (TheCollissionManager::Instance()->collides(gameObject::objects, this))
            {
                x_pos += 1;
                move_x += 1;
            }
        }
    };
    if (TheInputHandler::Instance()->keyDown(SDL_SCANCODE_UP))
    {
        up = true;
        down = false;
        left = false;
        right = false;

        currRow = 1;
        currFrame = int(((SDL_GetTicks() / 300) % 4));
        if (move_y >= 1152 || move_y <= 384)
        {
            y_pos -= 1;
            if (TheCollissionManager::Instance()->collides(gameObject::objects, this))
            {
                y_pos += 1;
                move_y += 1;
            }
        }
    }
    else if (TheInputHandler::Instance()->keyDown(SDL_SCANCODE_DOWN))
    {
        up = false;
        down = true;
        left = false;
        right = false;

        currRow = 2;
        currFrame = int(((SDL_GetTicks() / 300) % 4));
        if (move_y >= 1152 || move_y <= 384)
        {
            y_pos += 1;
            if (TheCollissionManager::Instance()->collides(gameObject::objects, this))
            {
                y_pos -= 1;
                move_y -= 1;
            }
        }
    }

    if (TheInputHandler::Instance()->keyDown(SDL_SCANCODE_SPACE) && !shoot)
    {
        if (up)
            TheShooter::Instance()->shoot_up(this);
        if (down)
            TheShooter::Instance()->shoot_down(this);
        if (left)
            TheShooter::Instance()->shoot_left(this);
        if (right)
            TheShooter::Instance()->shoot_right(this);
        shoot = true;
    }
    if (TheInputHandler::Instance()->keyUp(SDL_SCANCODE_SPACE))
    {
        shoot = false;
    }
    int curr_time = SDL_GetTicks();
    if ((TheCollissionManager::Instance()->collides(gameObject::enemy_objs, this)) && (curr_time - time >= 5000))
    {
        life--;
        time = curr_time;
    }
}

