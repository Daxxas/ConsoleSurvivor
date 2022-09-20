class Entity {
public:
    Entity(Vector2 position);

    virtual CHAR_INFO* Display() = 0;
    virtual Vector2 GetPosition() = 0;
    virtual void SetPosition(Vector2 position) = 0;
    bool isActive = false;
    Vector2 position;
    int spriteWidth;
    int spriteHeight;
};

