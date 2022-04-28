#include "point.h"

Point::Point(sf::RenderWindow* window, int x, int y)
    : window(window), x(x), y(y)
{
    this->r = new sf::RectangleShape(sf::Vector2f(5.0f, 5.0f));
    this->r->setOrigin(2.5f, 2.5f);
    this->r->setPosition(this->x, this->y);
}

Point::~Point()
{

}

void Point::render()
{
    this->window->draw(*this->r);
}