#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include "ball.h"

class screen
{
private:

public:
    screen();
    ~screen();

    void prepareScreen();
    void drawScreen();
    void printSymbol(int x, int y);
    void clearPreviousSymbol(int x, int y);
    void updateScreen(std::vector <ball*> balls) ;
};

#endif