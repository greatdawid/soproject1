#include "ball.h"
#include "ncurses.h"
#include <cstdlib>


void ball::ballUpdate(){
 
    int tmpX = this->currentX;
    int tmpY = this->currentY;


            if (tmpX + angleX > xsize -2) {
                tmpX = xsize -2;
                angleX = -angleX;
            }
            //probably left border is 1
            else if ( tmpX + angleX < 1) {
                tmpX = 1;
                angleX = -angleX; //reversing direction
            }
            
            else
            {
               tmpX = tmpX +angleX;
            }

            
            if (tmpY + angleY > ysize -2) {
                tmpY = ysize -2;
                //this is added
                //angleY *= 0.99;
                angleY = -angleY;
            }
            //probably left border is 1
            else if ( tmpY + angleY < 1) {
                tmpY = 1;
                angleY = -angleY; //reversing direction
            }
            else
            {
                //uncommented is added
                angleY += gravity*dt;
               //tmpY = tmpY + angleY;
                tmpY += angleY*dt + 0.5*gravity *dt*dt;
            }
            if ((tmpY == oldY) && (currentY == ysize -2)) {
                counter++;
            }
            //this if is responsible for stopping ball when ball is on ground
            if (counter >3) {
                angleX = 0;
                //isOver flag indicates that ball wont move in any direction, we can stop using updateBall function
                isOver = true;
            }
            
    oldX = currentX;
    oldY = currentY;
    currentX = tmpX;
    currentY = tmpY;

}

ball::ball(int angX, int angY){
    //getting terminal size
    getmaxyx(stdscr,this->ysize,this->xsize);
    this->currentX = xsize/2;
    this->currentY = ysize/2;
    //starting direction
    this->angleX = angX;
    this->angleY = angY;;
    this->oldX = 0;
    this->oldY = 0;
    this->gravity = 5.0;
    this->dt = 0.2;
    this->counter = 0;
    this->isOver = false;
    this->isInContact = false;

}