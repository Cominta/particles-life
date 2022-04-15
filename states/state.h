#ifndef STATE_H
#define STATE_H

#include <iostream>

class State
{
    public:
        State();
        ~State();

        virtual void update();

        virtual void render();
};

#endif