#ifndef MAINSTATE_H
#define MAINSTATE_H

#include "state.h"

class MainState : public State
{
    private:
        sf::RectangleShape* frame[4];
        sf::CircleShape* c = new sf::CircleShape(10.0f);

    public:
        MainState(sf::RenderWindow* window);
        ~MainState();

        void update();

        void render();
};

#endif