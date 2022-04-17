#ifndef MAINSTATE_H
#define MAINSTATE_H

#include "state.h"
#include "../shapes/square.h"

class MainState : public State
{
    private:
        sf::RectangleShape* frame[4];
        Square* square;

    public:
        MainState(sf::RenderWindow* window);
        ~MainState();

        void update(float deltaTime);

        void render();
};

#endif