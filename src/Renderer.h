class Renderer {
public:
    static const int DISPLAY_WIDTH = 90;
    static const int DISPLAY_HEIGHT = 50;
    void Render();
    Renderer(HANDLE, GameManager*);
private:
    CHAR_INFO buffer[DISPLAY_HEIGHT][DISPLAY_WIDTH];
    HANDLE hOutput;
    GameManager* gameManager;
    void DisplayArena();
};
