#include "Entity.h"

Entity::Entity(Vector2& position) : position(position) {
}

CHAR_INFO* Entity::Display() {
    return sprite;
}