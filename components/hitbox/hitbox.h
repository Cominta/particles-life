#ifndef HITBOX_H
#define HITBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Hitbox
{
    public:
        enum class sides
        {
            LEFT,
            TOP,
            RIGHT,
            BOTTOM,
            NONE
        };

    protected:
        sf::RenderWindow* window;
        sf::RectangleShape* hitboxShape;

    public:
        Hitbox(sf::RenderWindow* window);
        ~Hitbox();

        Hitbox::sides checkObject(sf::RectangleShape* frame); // для поверки столкновения с рамкой
        Hitbox::sides checkObject(Hitbox* hitbox); // передаем хитбокс объекта, с которым нужно проверить столкновение
        
        virtual void update();
        virtual void render();
};

#endif