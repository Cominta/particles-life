#include "hitboxSquare.h"

HitboxSquare::HitboxSquare(sf::RenderWindow* window, sf::RectangleShape* parentShape, float width, float height)
    : Hitbox(window), parentShape(parentShape), width(width), height(height)
{
    float thickness = 1.0f;

    this->hitboxShape.emplace_back(new sf::RectangleShape(sf::Vector2f(thickness, this->height))); // левая сторона
    this->hitboxShape.at(0)->setOrigin(thickness / 2, this->width / 2);
    this->hitboxShape.at(0)->setPosition(this->parentShape->getPosition().x - this->width / 2, this->parentShape->getPosition().y);

    this->hitboxShape.emplace_back(new sf::RectangleShape(sf::Vector2f(this->width, thickness))); // верхняя сторона
    this->hitboxShape.at(1)->setOrigin(this->width / 2, thickness / 2);
    this->hitboxShape.at(1)->setPosition(this->parentShape->getPosition().x, this->parentShape->getPosition().y - this->height / 2);

    this->hitboxShape.emplace_back(new sf::RectangleShape(sf::Vector2f(thickness, this->height))); // правая сторона
    this->hitboxShape.at(2)->setOrigin(thickness / 2, this->width / 2);
    this->hitboxShape.at(2)->setPosition(this->parentShape->getPosition().x + this->width / 2, this->parentShape->getPosition().y);

    this->hitboxShape.emplace_back(new sf::RectangleShape(sf::Vector2f(this->width, thickness))); // нижняя сторона
    this->hitboxShape.at(3)->setOrigin(this->width / 2, thickness / 2);
    this->hitboxShape.at(3)->setPosition(this->parentShape->getPosition().x, this->parentShape->getPosition().y + this->height / 2);

    for (auto &line : this->hitboxShape)
    {
        line->setFillColor(sf::Color::Green);
    }
}

HitboxSquare::~HitboxSquare()
{

}

void HitboxSquare::update()
{
    this->hitboxShape.at(0)->setPosition(this->parentShape->getPosition().x - this->width / 2, this->parentShape->getPosition().y);
    this->hitboxShape.at(1)->setPosition(this->parentShape->getPosition().x, this->parentShape->getPosition().y - this->height / 2);
    this->hitboxShape.at(2)->setPosition(this->parentShape->getPosition().x + this->width / 2, this->parentShape->getPosition().y);
    this->hitboxShape.at(3)->setPosition(this->parentShape->getPosition().x, this->parentShape->getPosition().y + this->height / 2);
}

void HitboxSquare::render()
{
    for (auto &line : this->hitboxShape)
    {
        this->window->draw(*line);
    }
}