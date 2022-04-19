#ifndef HITBOX_H
#define HITBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Hitbox
{
    protected:
        sf::RenderWindow* window;
        std::vector<sf::RectangleShape*> hitboxShape;

    public:
        Hitbox(sf::RenderWindow* window);
        ~Hitbox();

        virtual void update();

        virtual void render();

        int checkOut(sf::RectangleShape* (&frame)[4]);
};

#endif