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
    double gravityloss;
    double dt;
    double gravity;
    int id;
    int isOver;
    int xsize,ysize;
    void ballUpdate();
    ball(int angX, int angY);
    ~ball();
};


#endif