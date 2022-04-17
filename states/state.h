#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <SFML/Graphics.hpp>


class State
{
    public:
        enum class states
        {
            MAINSTATE
        };

    protected:
        sf::RenderWindow* window;

    public:
        states statesClass;

        State(sf::RenderWindow* window);
        ~State();

        virtual void update();
        virtual void update(float deltaTime);

        virtual void render();
};

#endif