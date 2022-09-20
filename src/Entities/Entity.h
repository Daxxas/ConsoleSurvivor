//
// Created by Jacques on 20/09/2022.
//

#ifndef CONSOLESURVIVOR_ENTITY_H
#define CONSOLESURVIVOR_ENTITY_H

#include "../Vector2.h"
#include <string>


class Entity {
public:
    Entity(Vector2 position);

    virtual std::string *Display() = 0;
    virtual Vector2 GetPosition() = 0;
    virtual void SetPosition(Vector2 position) = 0;

protected:
    Vector2 position;
};


#endif //CONSOLESURVIVOR_ENTITY_H
