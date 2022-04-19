#include "hitbox.h"

Hitbox::Hitbox(sf::RenderWindow* window)
    : window(window)
{

}

Hitbox::~Hitbox()
{

}

void Hitbox::update()
{

}

void Hitbox::render()
{

}

int Hitbox::checkOut(sf::RectangleShape* (&frame)[4])
{
    for (int i = 0; i < 4; i++)
    {
        if (frame[i]->getGlobalBounds().intersects(this->hitboxShape.at(i)->getGlobalBounds()))
        {
            return i;
        }
    }

    return -1;
}