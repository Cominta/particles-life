#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
#include "../components/hitbox/hitboxSquare.h"

class Square : public Shape
{
    private:
        sf::RectangleShape* shape;
        HitboxSquare* hitbox;
        float weight;
        float currentSpeedX;
        float currentSpeedY;

    public:
        Square(sf::RenderWindow* window, float width, float height, sf::Color color, float x, float y);
        ~Square();

        sf::RectangleShape* getShape() {return this->shape;};
        sf::Vector2f getPosition() {return this->shape->getPosition();}
        sf::Vector2f getSize() {return this->shape->getSize();};

        void setPosition(float x, float y) {this->shape->setPosition(x, y);};

        void update(float deltaTime);
        void render();
};

#endif