class InputHandler {
public:
    InputHandler();
    Vector2 GetMovementDirection();
    Vector2 * DetectMovementDirectionFromPlayer();
    bool IsVKeyPressed(int);
};