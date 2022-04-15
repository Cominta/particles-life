#ifndef ENGINE_H
#define ENGINE_H

#include <stack>
#include "states/mainState.h"

class Engine
{
    private:
        sf::Event sfEvent;
        sf::RenderWindow* window;
        std::stack<State*> states;

    public:
        Engine();
        ~Engine();

        void update();
        void updateSFML();

        void render();

        void start();
};

#endif