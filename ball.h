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
    bool outofbound(int x, int y);
    void ballUpdate();
    void anglerandomizer();
    bool coordsHasChanged();
    ball(int number);
    ~ball();
};


#endif