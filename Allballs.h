#ifndef ALLBALLS_H
#define ALLBALLS_H

#include <vector>
#include "ball.h"


class Allballs
{
private:

public:

    std::vector<ball*> ballsInScreen;
    int numberofballs;

    Allballs();
    ~Allballs();
    void addOneBall();
};


#endif