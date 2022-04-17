#include "square.h"

Square::Square(sf::RenderWindow* window, float width, float height, sf::Color color, float x, float y)
    : Shape(window)
{
    this->weight = 100;
    this->currentSpeed = 0;

    this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
    this->shape->setOrigin(width / 2, height / 2);
    this->shape->setFillColor(color);
    this->shape->setPosition(x, y);
}

Square::~Square()
{

}

void Square::update(float deltaTime)
{
    this->currentSpeed += 9.832f * deltaTime * weight;
    this->shape->move(0, this->currentSpeed);
}

void Square::render()
{
    this->window->draw(*this->shape);
}