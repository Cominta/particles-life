#ifndef ENGINE_H
#define ENGINE_H

#include <stack>
#include "states/mainState.h"

class Engine
{
    private:
        sf::Event sfEvent;
        sf::Clock deltaClock;
        sf::RenderWindow *window;
        std::stack<State *> states;
        
        float delta;
        bool mousePress;

    public:
        Engine();
        ~Engine();

        void start();
        
        void update();
        void updateSFML();
        void updateDelta();
        void render();

};

#endif