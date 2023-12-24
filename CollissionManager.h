#ifndef __CollissionManager__
#define __CollissionManager__

#include "gameObj.h"

class CollissionManager
{
private:
    CollissionManager() {}
    static CollissionManager *instance;

public:
    static CollissionManager *Instance();
    bool collides(std::vector<gameObject *> objs, gameObject *obj);
    bool collides2(std::vector<gameObject *> objs, std::vector<gameObject *> objs2);
    bool collides_with_buffer(std::vector<gameObject *> objs, gameObject *obj, int buffer);
    bool collides_with_left(std::vector<gameObject *> objs, std::vector<gameObject *> objs2, int buffer);
    bool collides_with_right(std::vector<gameObject *> objs, std::vector<gameObject *> objs2, int buffer);
    bool collides_with_top(std::vector<gameObject *> objs, std::vector<gameObject *> objs2, int buffer);
    bool collides_with_bottom(std::vector<gameObject *> objs, std::vector<gameObject *> objs2, int buffer);
    gameObject *get_colliding_object(std::vector<gameObject *> objs, gameObject *obj);
};

typedef CollissionManager TheCollissionManager;

#endif