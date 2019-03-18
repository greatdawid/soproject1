#ifndef SCREEN_H
#define SCREEN_H

#include "Allballs.h"

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
    void updateScreen(Allballs* ballsvector) ;
};

#endif