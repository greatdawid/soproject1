#include <iostream>
#include <ncurses.h>
#include <vector>
#include <time.h>
#include <thread>
#include <unistd.h>
#include "screen.h"
#include "Allballs.h"

bool isRunning = true;
screen *Screen; 
Allballs *ballsvector;

void exitfunction(){
    while(isRunning){
        char key = getchar();
        if(key == 'q')
        isRunning = false;
    }
}

void ballThreadFunction(int ballId){
 
    while(isRunning){
        usleep(50000);
        ballsvector->ballsInScreen[ballId]->ballUpdate();
    }
    //chanigng x and y position

    // ballsvector->ballsInScreen[ballId]->currentX = -1;
    // ballsvector->ballsInScreen[ballId]->currentY = -1;
}


void updateScreenFunction(){

    while(isRunning){
        usleep(10000);
        Screen->updateScreen(ballsvector);
    }
    //destroying Screen object
    delete Screen;
}

int main(){
    
    
    Screen = new screen();
  //  Screen = new screen();
    ballsvector = new Allballs();
    srand(time(NULL));
    std::vector<std::thread> ballsthreads;
    std::thread screenThread(updateScreenFunction);
    std::thread exitThread(exitfunction);
   // std::thread oneballThread;

    for(int i=0;i<5;i++){

        ballsvector->addOneBall();
        ballsthreads.push_back(std::thread(ballThreadFunction,i));
        sleep(1);
        if(!isRunning) break;

    }

    

    screenThread.join();
    exitThread.join();
    endwin();
     for(int i = 0; i < 5; i++)
    {
         ballsthreads[i].join();
    }
    
    return 0;
}