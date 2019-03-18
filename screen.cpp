#include <iostream>
#include <ncurses.h>
#include "screen.h"
#include "Allballs.h"

screen::~screen(){

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

void screen::updateScreen(Allballs *ballsvector){
    for(int i = 0; i < ballsvector->numberofballs; i++)
    {
            //printing symbols
            clearPreviousSymbol(ballsvector->ballsInScreen[i]->oldX,ballsvector->ballsInScreen[i]->oldY);
            printSymbol(ballsvector->ballsInScreen[i]->currentX, ballsvector->ballsInScreen[i]->currentY);
        
    }
    refresh();
}