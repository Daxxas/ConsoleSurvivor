class Renderer {
public:
    static const int DISPLAY_WIDTH = 140;
    static const int DISPLAY_HEIGHT = 50;
    void Render();
    Renderer(HANDLE&);
private:
    CHAR_INFO buffer[DISPLAY_HEIGHT][DISPLAY_WIDTH];
    HANDLE hOutput;
    void DisplayArena();
    GameManager* gameManager;
};
