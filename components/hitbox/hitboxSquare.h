#ifndef HITBOXSQUARE_H
#define HITBOXSQUARE_H

#include "hitbox.h"

class HitboxSquare : public Hitbox
{
    private:
        sf::RectangleShape* parentShape;
        float width;
        float height;

    public:
        HitboxSquare(sf::RenderWindow* window, sf::RectangleShape* parentShape,float width, float height);
        ~HitboxSquare();

        void update();
        void render();
};

#endif