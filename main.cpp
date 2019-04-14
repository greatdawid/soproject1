#include <ncurses.h>
#include <vector>
#include <time.h>
#include <thread>
#include <unistd.h>
#include "screen.h"
#include <mutex>
#include <condition_variable>

bool isRunning = true;
screen *Screen; 

std::vector <ball*> balls;
std::vector<std::thread> ballsthreads;
std::mutex mu;
std::condition_variable cond;
int ballsInSleep = 0;

void exitfunction(){
    while(isRunning){
        char key = getch();
        if(key == 'q')
        isRunning = false;
    }
}
//to do comprare coords
bool isNear(int b1x,int b1y, int b2x, int b2y){

    if (abs(b1x-b2x) <= 1 && abs(b1y-b2y) <=1) {
        return true;
    }
    else
    {
        return false;
    }
    
    
}
void checkingCollision(int number, int & lastContact){

    for(int i = 0; i < balls.size(); i++ )
    {
        if (i == number) continue; 
        
        int x = balls[i]->currentX;
        int y = balls[i]->currentY;
        if (isNear(x,y,balls[number]->currentX, balls[number]->currentY) && !(number ==lastContact)) {
            // collision code is here
            balls[i]->isInContact = true;
            balls[number] -> isInContact = true;
            lastContact = number;
        }
    }  
}

bool sleepAllowed(int ballId)
{   
    if (balls[ballId]->isInContact && ballsInSleep < 2) {
         ballsInSleep++;
         return true;
    }
    else
    {
        return false;
    }
      
}

void ballThreadFunction(int ballId){
    int internalCounter = 3;
    int lastContact = -1;
    while(isRunning){

        usleep(50000);
        internalCounter--;
        if(internalCounter < 0) lastContact = -1;
//probably mutex here
        mu.lock();
        checkingCollision(ballId, lastContact);
      //  mu.unlock();

        if(sleepAllowed(ballId)){
            // //smth like double speed for a balls in contact
            // mu.lock();
            // ballsLocked++;
            balls[ballId]->isInContact = false;
            mu.unlock();
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            balls[ballId] -> ballUpdate();
            ballsInSleep--;
        }
        else{
            
            //not sure about this
            balls[ballId] -> isInContact = false;
            mu.unlock();
            balls[ballId] -> ballUpdate();
            //isOver means ball wont move in any direction so calling ballUpdate is pointless
            if(balls[ballId]->isOver) break;
        }
    }
    //chanigng x and y position
}

int randAngleY(){
    int tmp=0;

    tmp=rand()%10-10;
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

// (b1x==b2x && b1y==b2y) || (b1x==b2x-1 && b1y ==b2y) || (b1x == b2x-1 && b1y ==b2y-1) || 
//         (b1x == b2y && b1y == b2y -1) || (b1x == b2x +1 && b1y == b2y+1) ||
void isCollision(std::vector<ball*> balls){

    for(int i = 0; i < balls.size(); i++)
    {

        int x = balls[i]->currentX;
        int y = balls[i]->currentY;
        for(int j = 0; j < balls.size(); j++)
        {
            if(i==j) continue;
           // if(isNear(x,y, balls[j]->currentX, balls[j]->currentY))           
            
            
        }
        

}


}

void updateScreenFunction(){

    while(isRunning){
        //microseconds
        usleep(1000);
        Screen->updateScreen(balls);
    }
    //destroying Screen object
    delete Screen;
}

void ballsInMotion(){
    int i=0;
    while(isRunning){
        ball *tmpball = new ball(randAngleX(),randAngleY());
        balls.push_back(tmpball);
        ballsthreads.push_back(std::thread(ballThreadFunction,i));
        sleep(3);
        i++;
        if(!isRunning) return;
    }   
} 

void checkthread(){
    while(isRunning){
        
    }
    
}

int main(){
    
    
    Screen = new screen();
    srand(time(NULL));

    std::thread screenThread(updateScreenFunction);
    std::thread exitThread(exitfunction);
    std::thread ballThread(ballsInMotion);

//threads are working

    ballThread.join();
    screenThread.join();
    exitThread.join();
     for(int i = 0; i < ballsthreads.size(); i++)
    {
         ballsthreads[i].join();
    }
    endwin();
    return 0;
}