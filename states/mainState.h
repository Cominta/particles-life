#ifndef MAINSTATE_H
#define MAINSTATE_H

#include "state.h"
#include "particles/red.h"
#include <vector>
#include "../components/quadtree/quadtree.h"

class MainState : public State
{
    private:
        sf::RectangleShape* range;
        std::vector<Point*> found;

        Quadtree* quadtree;

    public:
        MainState(sf::RenderWindow* window);
        ~MainState();

        void update(float deltaTime, bool mousePress);
        void render();
};

#endif