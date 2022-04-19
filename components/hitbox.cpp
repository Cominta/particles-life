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

Hitbox::sides Hitbox::checkObject(sf::RectangleShape* frame)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->hitboxShape.at(i)->getGlobalBounds().intersects(frame->getGlobalBounds()))
        {
            switch (i)
            {
                case 0:
                    return Hitbox::sides::LEFT;
                
                case 1:
                    return Hitbox::sides::TOP;

                case 2:
                    return Hitbox::sides::RIGHT;

                case 3:
                    return Hitbox::sides::BOTTOM;

                default:
                    return Hitbox::sides::NONE;
            }
        }
    }
}

Hitbox::sides Hitbox::checkObject(Hitbox* hitbox)
{

}