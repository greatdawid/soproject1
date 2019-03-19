#include <ncurses.h>
#include <vector>
#include <time.h>
#include <thread>
#include <unistd.h>
#include "screen.h"

bool isRunning = true;
screen *Screen; 
//Allballs *ballsvector;
std::vector <ball *> balls;

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
        balls[ballId]->ballUpdate();
        //isOver means ball wont move in any direction so calling ballUpdate is pointless
        if(balls[ballId]->isOver) break;
    }
    //chanigng x and y position
}


int randAngleY(){
    int tmp=0;

    tmp=rand()%10+5;
    return tmp;
}

int randAngleX(){
    int tmp=0;
    do
    {
    tmp=rand()%3-1;
    } while (tmp==0);
    return tmp;
}

void updateScreenFunction(){

    while(isRunning){
        usleep(10000);
        Screen->updateScreen(balls);
    }
    //destroying Screen object
    delete Screen;
}

int main(){
    
    
    Screen = new screen();
  //  Screen = new screen();
   // ballsvector = new Allballs();
    srand(time(NULL));
    std::vector<std::thread> ballsthreads;
    std::thread screenThread(updateScreenFunction);
    std::thread exitThread(exitfunction);

    for(int i=0;i<5;i++){
        ball *tmpball = new ball(randAngleX(),randAngleY());
        balls.push_back(tmpball);
        ballsthreads.push_back(std::thread(ballThreadFunction,i));
        sleep(1);
        if(!isRunning) break;
    }

    

    screenThread.join();
    exitThread.join();
    endwin();
     for(int i = 0; i < ballsthreads.size(); i++)
    {
         ballsthreads[i].join();
    }
    
    return 0;
}