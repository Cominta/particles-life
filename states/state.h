#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class State
{
    protected:
        sf::RenderWindow* window;

    public:
        State(sf::RenderWindow* window);
        ~State();

        virtual void update();

        virtual void render();
};

#endif