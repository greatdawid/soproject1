#include "ball.h"
#include "ncurses.h"
#include <cstdlib>

bool ball::outofbound(int x, int y){
    int xsize,ysize = 0;
    bool outofscreen = false;
    //getting terminal size
    getmaxyx(stdscr,ysize,xsize);
    if ( x <= 0 || x >= xsize|| y <= 0 || y >= ysize ) {
        return true;
    }
    else
    {
        return false;
    }
    
}

void ball::ballUpdate(){
    int xsize,ysize = 0;
    //getting terminal size
    getmaxyx(stdscr,ysize,xsize);

    int tmpX = this->currentX;
    int tmpY = this->currentY;

  //  while(true){

            if (tmpX + angleX > xsize -2) {
                tmpX = xsize -2;
                angleX = -angleX;
            }
            //probably left border is 1
            if ( tmpX + angleX < 1) {
                tmpX = 1;
                angleX = -angleX; //reversing direction
            }
            
            else
            {
                //angleX = gravity *dt;
                tmpX = tmpX +angleX ;
               // angleX +=angleX *dt + 0.5*gravity *dt*dt;
            }

            
            if (tmpY + angleY > ysize -2) {
                tmpY = ysize -2;
                //this is added
                angleY *= 0.99;
                angleY = -angleY;
            }
            //probably left border is 1
            if ( tmpY + angleY < 1) {
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
            if (counter >3) {
                angleX = 0;
            }
            
          //  if (!outofbound(tmpX,tmpY)) {
        //        //exiting while loop
  //              break;
            //}
        
   // }
    oldX = currentX;
    oldY = currentY;
    currentX = tmpX;
    currentY = tmpY;

}

void ball::anglerandomizer(){
    int tmpX,tmpY;
   do
   {
        angleX = rand()%2-1;        
        //    tmpX = 0;
        //    tmpY = 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             tmpX = rand()%2-1;
        angleY = rand()%2-1;
  } while ((tmpX == -1 && tmpY == -1) || (tmpX == 0 && tmpY == -1) || (tmpX == 1 && tmpY == -1) || (tmpX == 0 && tmpY == 0));
}

bool ball::coordsHasChanged(){
    return currentX != oldX || currentY != oldY; 
     }

ball::ball(int number){
    int yScreen = 0,xScreen = 0;
    getmaxyx(stdscr,yScreen,xScreen);
    this->currentX = xScreen/2;
    this->currentY = yScreen/2;
    //starting direction
    this->angleX = -2;
    this->angleY = 15;
    //anglerandomizer();
    this->id = number;
    this->oldX = 0;
    this->oldY = 0;
    this->gravity = 5.0;
    this->dt = 0.2;
    this->counter = 0;
  //  this->isOver = false;

}