#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Point
{
    private:
        sf::RenderWindow* window;

    public:
        sf::RectangleShape* r;
        
        int x;
        int y;
        int width; 
        int height;

        Point(sf::RenderWindow* window, int x, int y);
        ~Point();

        void render();
};

#endif