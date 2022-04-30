#ifndef HITBOXSQUARE_H
#define HITBOXSQUARE_H

#include "hitbox.h"

class HitboxSquare : public Hitbox
{
    private:
        sf::CircleShape* parentShape;

    public:
        int width;
        int height;

        int x;
        int y;

        HitboxSquare(sf::RenderWindow* window, float width, float height, sf::CircleShape* parentShape = nullptr);
        ~HitboxSquare();

        bool intersects(HitboxSquare* other);

        void update();
        void render();

        void setPosition(int x, int y) {this->hitboxShape->setPosition(sf::Vector2f(x, y)); this->x = x; this->y = y;};
        sf::RectangleShape* getShape() {return this->hitboxShape;};
};

#endif