#include "CollissionManager.h"

CollissionManager *CollissionManager::instance = nullptr;

CollissionManager *CollissionManager::Instance()
{
    if (instance == nullptr)
    {
        instance = new CollissionManager();
        return instance;
    }
    return instance;
}
//just checks for collission
bool CollissionManager::collides(std::vector<gameObject *> objs, gameObject *obj)
{
    for (int i = 0; i < objs.size(); i++)
    {
        if (objs[i]->get_name() != obj->get_name())
        {
            if (objs[i]->get_x() + objs[i]->get_width() >= obj->get_x() &&
                objs[i]->get_x() <= obj->get_x() + obj->get_width() &&
                objs[i]->get_y() + objs[i]->get_height() >= obj->get_y() &&
                objs[i]->get_y() <= obj->get_y() + obj->get_height())
            {
                return true;
            }
        }
    }
    return false;
}
//checks for collission after adding a buffer(boundry)
bool CollissionManager::collides_with_buffer(std::vector<gameObject *> objs, gameObject *obj, int buffer)
{
    for (int i = 0; i < objs.size(); i++)
    {
        if (objs[i]->get_name() != obj->get_name())
        {
            if (objs[i]->get_x() + objs[i]->get_width() + buffer >= obj->get_x() &&
                objs[i]->get_x() - buffer <= obj->get_x() + obj->get_width() &&
                objs[i]->get_y() + objs[i]->get_height() + buffer >= obj->get_y() &&
                objs[i]->get_y() - buffer <= obj->get_y() + obj->get_height())
            {
                return true;
            }
        }
    }
    return false;
}
//checks collission of two vectors
bool CollissionManager::collides2(std::vector<gameObject *> objs, std::vector<gameObject *> objs2)
{
    for (int i = 0; i < objs.size(); i++)
    {
        for (int j = 0; j < objs2.size(); j++)
        {
            if (objs[i]->get_name() != objs2[j]->get_name())
            {
                if (objs[i]->get_x() + objs[i]->get_width() >= objs2[j]->get_x() &&
                    objs[i]->get_x() <= objs2[j]->get_x() + objs2[j]->get_width() &&
                    objs[i]->get_y() + objs[i]->get_height() >= objs2[j]->get_y() &&
                    objs[i]->get_y() <= objs2[j]->get_y() + objs2[j]->get_height())
                {
                    return true;
                }
            }
        }
    }
    return false;
}
//checks collission with right side
bool CollissionManager::collides_with_right(std::vector<gameObject *> objs, std::vector<gameObject *> objs2, int buffer)
{
    for (int i = 0; i < objs.size(); i++)
    {
        for (int j = 0; j < objs2.size(); j++)
        {
            if (objs[i]->get_name() != objs2[j]->get_name())
            {
                if (objs[i]->get_x() + objs[i]->get_width() + buffer >= objs2[j]->get_x() &&
                    objs[i]->get_x() - buffer <= objs2[j]->get_x() + 1 &&
                    objs[i]->get_y() + objs[i]->get_height() + buffer >= objs2[j]->get_y() &&
                    objs[i]->get_y() - buffer <= objs2[j]->get_y() + objs2[j]->get_height())
                {
                    return true;
                }
            }
        }
    }
    return false;
}
//checks collission with left side
bool CollissionManager::collides_with_left(std::vector<gameObject *> objs, std::vector<gameObject *> objs2, int buffer)
{
    for (int i = 0; i < objs.size(); i++)
    {
        for (int j = 0; j < objs2.size(); j++)
        {
            if (objs[i]->get_name() != objs2[j]->get_name())
            {
                if (objs[i]->get_x() + objs[i]->get_width() + buffer >= objs2[j]->get_x() + objs2[j]->get_width() - 1 &&
                    objs[i]->get_x() - buffer <= objs2[j]->get_x() + objs2[j]->get_width() &&
                    objs[i]->get_y() + objs[i]->get_height() + buffer >= objs2[j]->get_y() &&
                    objs[i]->get_y() - buffer <= objs2[j]->get_y() + objs2[j]->get_height())
                {
                    return true;
                }
            }
        }
    }
    return false;
}
//checks collission with top side
bool CollissionManager::collides_with_top(std::vector<gameObject *> objs, std::vector<gameObject *> objs2, int buffer)
{
    for (int i = 0; i < objs.size(); i++)
    {
        for (int j = 0; j < objs2.size(); j++)
        {
            if (objs[i]->get_name() != objs2[j]->get_name())
            {
                if (objs[i]->get_x() + objs[i]->get_width() + buffer >= objs2[j]->get_x() &&
                    objs[i]->get_x() - buffer <= objs2[j]->get_x() + objs2[j]->get_width() &&
                    objs[i]->get_y() + objs[i]->get_height() + buffer >= objs2[j]->get_y() &&
                    objs[i]->get_y() - buffer <= objs2[j]->get_y() + 1)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
//checks collission with bottom side
bool CollissionManager::collides_with_bottom(std::vector<gameObject *> objs, std::vector<gameObject *> objs2, int buffer)
{
    for (int i = 0; i < objs.size(); i++)
    {
        for (int j = 0; j < objs2.size(); j++)
        {
            if (objs[i]->get_name() != objs2[j]->get_name())
            {
                if (objs[i]->get_x() + objs[i]->get_width() + buffer >= objs2[j]->get_x() &&
                    objs[i]->get_x() - buffer <= objs2[j]->get_x() + objs2[j]->get_width() &&
                    objs[i]->get_y() + objs[i]->get_height() + buffer >= objs2[j]->get_y() + objs2[j]->get_height() - 1 &&
                    objs[i]->get_y() - buffer <= objs2[j]->get_y() + objs2[j]->get_height())
                {
                    return true;
                }
            }
        }
    }
    return false;
}
//returns the object with which it is colliding
gameObject *CollissionManager::get_colliding_object(std::vector<gameObject *> objs, gameObject *obj)
{
    for (int i = 0; i < objs.size(); i++)
    {
        if (objs[i]->get_name() != obj->get_name())
        {
            if (objs[i]->get_x() + objs[i]->get_width() >= obj->get_x() &&
                objs[i]->get_x() <= obj->get_x() + obj->get_width() &&
                objs[i]->get_y() + objs[i]->get_height() >= obj->get_y() &&
                objs[i]->get_y() <= obj->get_y() + obj->get_height())
            {
                return objs[i];
            }
        }
    }
    return nullptr;
}