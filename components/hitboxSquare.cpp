#include "hitboxSquare.h"

HitboxSquare::HitboxSquare(sf::RenderWindow* window, sf::RectangleShape* parentShape, float width, float height)
    : Hitbox(window), parentShape(parentShape)
{
    this->hitboxShape = new sf::RectangleShape(sf::Vector2f(width, height));
    this->hitboxShape->setOrigin(width / 2, height / 2);
    this->hitboxShape->setFillColor(sf::Color::Transparent);
    this->hitboxShape->setOutlineThickness(1.0f);
    this->hitboxShape->setOutlineColor(sf::Color::Green);
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