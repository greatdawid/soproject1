#ifndef BALL_H
#define BALL_H

class ball
{
private:

public:
    int oldX;
    int oldY;
    int currentX;
    int currentY;
    int counter;
    double angleX;
    double angleY;
    double dt;
    double gravity;
    int isOver;
    bool isInContact;
    int xsize,ysize;
    void ballUpdate();
    ball(int angX, int angY);
    ~ball();
};


#endif