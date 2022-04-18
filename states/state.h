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
        sf::Vector2f mousePosition;

    public:
        states statesClass;

        State(sf::RenderWindow* window);
        ~State();

        virtual void update();
        virtual void update(float deltaTime, bool mousePress);
        void updateMouse();

        virtual void render();
};

#endif