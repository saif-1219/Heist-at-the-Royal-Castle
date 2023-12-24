#include "Collectibles.h"

void Collectibles::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    gameObject::Collectible_objects.push_back(this);
    gameObject::load(x, y, w, h, id, x_s, y_s, background);
}

void Collectibles::draw(SDL_Renderer *renderer)
{
    Static_tree::draw(renderer);
}

void Collectibles::update()
{
    Static_tree::update();
    if (TheCollissionManager::Instance()->collides(gameObject::player_objs, this))
    {

        collected = true;
        gameObject::remove_from_vector(gameObject::Collectible_objects, this);
        gameObject::keys++;
        Mix_PlayChannel(-1, Game::keyPickupSound, 0);
    }
}

