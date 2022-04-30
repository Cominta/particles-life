#include "red.h"

Red::Red(sf::RenderWindow* window, int d, int x, int y)
    : Particle(window, d, x, y)
{
    this->shape = new sf::CircleShape(this->d / 2);
    this->shape->setOrigin(this->d / 2, this->d / 2);
    this->shape->setFillColor(sf::Color::Red);
    this->shape->setPosition(this->x, this->y);

    this->hitbox = new HitboxSquare(this->window, this->d, this->d, this->shape);
}

Red::~Red()
{

}

void Red::update()
{
    this->hitbox->update();
}

void Red::render()
{
    this->window->draw(*this->shape);
    this->hitbox->render();
}