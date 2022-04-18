#ifndef MAINSTATE_H
#define MAINSTATE_H

#include "state.h"
#include "../shapes/square.h"
#include <vector>

class MainState : public State
{
    private:
        sf::RectangleShape* frame[4];
        std::vector<Square* > objects;
        float margin;

    public:
        MainState(sf::RenderWindow* window);
        ~MainState();

        void update(float deltaTime, bool mousePress);

        void render();
};

#endif