#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape
{
    private:
        sf::RectangleShape* shape;
        float weight;
        float currentSpeed;

    public:
        Square(sf::RenderWindow* window, float width, float height, sf::Color color, float x, float y);
        ~Square();

        void update(float deltaTime);

        void render();
};

#endif