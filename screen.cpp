#include <iostream>
#include <ncurses.h>
#include <vector>
#include "screen.h"

screen::~screen(){
    endwin();
}

screen::screen(){

    prepareScreen();
    drawScreen();
}

void screen::prepareScreen(){
    initscr();
    // clear();
    noecho();
    // invisble cursor is set
    curs_set(0);
    refresh();
}

void screen::printSymbol(int x, int y){
    mvprintw(y,x, "o");
}

void screen::clearPreviousSymbol(int x, int y){
    mvprintw(y,x, " ");
}
void screen::drawScreen(){

    int xsize=0,ysize=0;
    getmaxyx(stdscr,ysize, xsize);
    for(int i = 0; i < xsize; i++)
    {
        //drawing columns
        mvprintw(0,i,"-");
        mvprintw(ysize-1,i,"-");
    }

    for(int i = 0; i < xsize; i++)
    {
        //drawing rows
        mvprintw(i,0, "|");
        mvprintw(i,xsize-1,"|");
    }
    refresh();
}

// void screen::updateScreen(Allballs *ballsvector){
//     for(int i = 0; i < ballsvector->numberofballs; i++)
//     {
//             //printing symbols
//             clearPreviousSymbol(ballsvector->ballsInScreen[i]->oldX,ballsvector->ballsInScreen[i]->oldY);
//             printSymbol(ballsvector->ballsInScreen[i]->currentX, ballsvector->ballsInScreen[i]->currentY);
        
//     }
//     refresh();
// }
void screen::updateScreen(std::vector <ball*> balls){
    for(int i = 0; i < balls.size(); i++)
    {
            //printing symbols
            clearPreviousSymbol(balls[i]->oldX,balls[i]->oldY);
            printSymbol(balls[i]->currentX, balls[i]->currentY);
        
    }
    refresh();
}