#include "hitboxSquare.h"

HitboxSquare::HitboxSquare(sf::RenderWindow* window, sf::RectangleShape* parentShape, float width, float height)
    : Hitbox(window), parentShape(parentShape), width(width), height(height)
{
    float thickness = 1.0f;

    this->hitboxShape = new sf::RectangleShape(sf::Vector2f(width, height));
    this->hitboxShape->setOutlineColor(sf::Color::Green);
    this->hitboxShape->setFillColor(sf::Color::Transparent);
    this->hitboxShape->setOutlineThickness(thickness);
    this->hitboxShape->setOrigin(width / 2, height / 2);
}

HitboxSquare::~HitboxSquare()
{

}

void HitboxSquare::update()
{
    this->hitboxShape->setPosition(this->parentShape->getPosition());
    this->hitboxShape->setRotation(this->parentShape->getRotation());
}

void HitboxSquare::render()
{
    this->window->draw(*this->hitboxShape);
}