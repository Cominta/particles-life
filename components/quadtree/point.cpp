#include "point.h"

Point::Point(sf::RenderWindow* window, int x, int y)
    : window(window), x(x), y(y)
{
    this->c = new sf::CircleShape(5.0f);
    this->c->setOrigin(2.5f, 2.5f);
    this->c->setPosition(this->x, this->y);
}

Point::~Point()
{

}

void Point::render()
{
    this->window->draw(*this->c);
}