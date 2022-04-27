#ifndef MAINSTATE_H
#define MAINSTATE_H

#include "state.h"
#include "../shapes/square.h"
#include <vector>
#include "../components/quadtree/quadtree.h"

class MainState : public State
{
    private:
        std::vector<Square*> objects;

        Quadtree* quadtree;

    public:
        MainState(sf::RenderWindow* window);
        ~MainState();

        void update(float deltaTime, bool mousePress);
        void render();
};

#endif