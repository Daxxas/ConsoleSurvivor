class BatEnemy : public Entity {
public:
    BatEnemy(Vector2& position);
    CHAR_INFO* Display() override;
    void Update() override;

};