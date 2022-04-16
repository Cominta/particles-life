#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>

class Shape
{
    protected:
        sf::RenderWindow* window;

    public:
        Shape(sf::RenderWindow* window);
        Shape();

        virtual void update();

        virtual void render();
};

#endif