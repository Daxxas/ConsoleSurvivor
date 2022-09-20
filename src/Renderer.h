//
// Created by Jacques on 20/09/2022.
//

#ifndef CONSOLESURVIVOR_RENDERER_H
#define CONSOLESURVIVOR_RENDERER_H

#include <windows.h>


class Renderer {
public:
    static const int DISPLAY_WIDTH = 600;
    static const int DISPLAY_HEIGHT = 50;
    void Render();
    Renderer(HANDLE);
private:
    CHAR_INFO buffer[DISPLAY_HEIGHT][DISPLAY_WIDTH];
    HANDLE hOutput;
    void DisplayArena();
};


#endif //CONSOLESURVIVOR_RENDERER_H
