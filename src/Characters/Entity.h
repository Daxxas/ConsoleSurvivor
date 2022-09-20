//
// Created by Jacques on 20/09/2022.
//

#ifndef CONSOLESURVIVOR_ENTITY_H
#define CONSOLESURVIVOR_ENTITY_H

#include <windows.h>

class Entity {
public:
    Entity(Vector2 position);

    virtual std::string* Display();
    virtual Vector2 GetPosition();
    virtual void SetPosition(Vector2 position);

protected:
    Vector2 position;
};


#endif //CONSOLESURVIVOR_ENTITY_H
