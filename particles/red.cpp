#include "red.h"

Red::Red(sf::RenderWindow* window, int d, int x, int y)
    : Particle(window, d, x, y)
{
    this->currentSpeedX = 0;
    this->currentSpeedY = 0;

    this->classP = Particle::particleClass::RED;

    this->shape = new sf::CircleShape(this->d / 2);
    this->shape->setOrigin(this->d / 2, this->d / 2);
    this->shape->setFillColor(sf::Color::Red);
    this->shape->setPosition(this->x, this->y);

    this->hitbox = new HitboxSquare(this->window, this->d, this->d, this->shape);
    this->hitboxRange = new HitboxSquare(this->window, this->d * 20, this->d * 20, this->shape);
}

Red::~Red()
{

}

void Red::update(float deltaTime, std::vector<Particle*> foundRange)
{
    this->hitbox->update();
    this->hitboxRange->update();

    if (foundRange.size() == 1)
    {
        if (this->currentSpeedX < 0)
        {
            this->currentSpeedX += 5;
        }

        else if(this->currentSpeedX > 0)
        {
            this->currentSpeedX -= 5;
        }

        if (this->currentSpeedY < 0)
        {
            this->currentSpeedY += 5;
        }

        else if (this->currentSpeedY > 0)
        {
            this->currentSpeedY -= 5;
        }
    }
    
    else
    {
        for (auto &particle : foundRange)
        {
            if ((*particle).classP == Particle::particleClass::RED && particle != this)
            {
                int distance = this->x - (*particle).x;
                this->currentSpeedX += -distance * 0.1f;

                distance = this->y - (*particle).y;
                this->currentSpeedY += -distance * 0.1f;
            }
        }
    }

    this->shape->setPosition(this->shape->getPosition().x + this->currentSpeedX * deltaTime, this->shape->getPosition().y + this->currentSpeedY * deltaTime);
    this->x = this->shape->getPosition().x;
    this->y = this->shape->getPosition().y;
}

void Red::render()
{
    this->window->draw(*this->shape);

    this->hitbox->render();
    this->hitboxRange->render();
}