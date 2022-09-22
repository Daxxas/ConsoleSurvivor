#ifndef CONSOLESURVIVOR_POOL_H
#define CONSOLESURVIVOR_POOL_H

#include <iostream>
#include <list>

template <class Entity>
class Pool {
private:
    std::list<Entity*> pool;
public:
    Entity* Get();
    void Return(Entity*);
};


#endif //CONSOLESURVIVOR_POOL_H
