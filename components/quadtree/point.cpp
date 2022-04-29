#include "point.h"

Point::Point(sf::RenderWindow* window, int x, int y)
    : window(window), x(x), y(y)
{
    this->width = 5;
    this->height = 5;

    this->r = new sf::RectangleShape(sf::Vector2f(this->width, this->height ));
    this->r->setOrigin(this->width / 2, this->height / 2);
    this->r->setPosition(this->x, this->y);
}

Point::~Point()
{

}

void Point::render()
{
    this->window->draw(*this->r);
}