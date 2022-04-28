#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Point
{
    private:
        sf::RenderWindow* window;
        sf::RectangleShape* r;

    public:
        int x;
        int y;

        Point(sf::RenderWindow* window, int x, int y);
        ~Point();

        void render();
};

#endif