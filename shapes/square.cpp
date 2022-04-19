#include "square.h"

Square::Square(sf::RenderWindow* window, float width, float height, sf::Color color, float x, float y)
    : Shape(window)
{
    this->weight = 100;
    this->currentSpeedX = 0;
    this->currentSpeedY = 0;

    this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
    this->shape->setOrigin(width / 2, height / 2);
    this->shape->setFillColor(color);
    this->shape->setPosition(x, y);

    this->hitbox = new HitboxSquare(this->window, this->shape, this->shape->getSize().x, this->shape->getSize().x);
}

Square::~Square()
{

}

void Square::update(float deltaTime, sf::RectangleShape* (&frame)[4])
{
    this->currentSpeedY += 9.832f * deltaTime * weight;
    
    for (auto &line : frame)
    {
        Hitbox::sides result = this->hitbox->checkObject(line);

        if (result == Hitbox::sides::BOTTOM)
            this->currentSpeedY = 0;
    }

    // if (result != -1)
    // {
    //     if (result == 3) {
    //         this->currentSpeedY = 0;
    //     }
    // }

    // else
    // {
    //     this->currentSpeedY += 9.832f * deltaTime * weight;
    // }

    this->shape->move(this->currentSpeedX, this->currentSpeedY);
    this->hitbox->update();
}

void Square::render()
{
    this->window->draw(*this->shape);
    this->hitbox->render();
}