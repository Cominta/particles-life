#include "hitboxSquare.h"

HitboxSquare::HitboxSquare(sf::RenderWindow* window, float width, float height, sf::CircleShape* parentShape)
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

bool HitboxSquare::intersects(HitboxSquare* other)
{
    return ((*other).x + (*other).width >= this->x - this->width / 2 && (*other).x - (*other).width <= this->x + this->width / 2 &&
            (*other).y + (*other).height >= this->y - this->height / 2 && (*other).y - (*other).height <= this->y + this->height / 2);
}

void HitboxSquare::update()
{
    this->x = this->parentShape->getPosition().x;
    this->y = this->parentShape->getPosition().y;

    if (this->parentShape != nullptr)
    {
        this->hitboxShape->setPosition(x, y);
        this->hitboxShape->setRotation(this->parentShape->getRotation());
    }
}

void HitboxSquare::render()
{
    this->window->draw(*this->hitboxShape);
}