#include "Allballs.h"


Allballs::Allballs(){
    this->numberofballs = 0;
}

Allballs::~Allballs(){
}

void Allballs::addOneBall(){

    ball* oneBall = new ball(this->numberofballs++);
    this->ballsInScreen.push_back(oneBall);
}