#ifndef MAINSTATE_H
#define MAINSTATE_H

#include <SFML/Graphics.hpp>
#include "state.h"

class MainState : public State
{
    private:


    public:
        MainState();
        ~MainState();

        void update();

        void render();
};

#endif