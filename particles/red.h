#ifndef RED_H
#define RED_H 

#include "particle.h"

class Red  : public Particle
{
    public:
        Red(sf::RenderWindow* window, int d, int x, int y);
        ~Red();

        void update();
        void render();

        HitboxSquare* getHitbox() {return this->hitbox;};
};

#endif