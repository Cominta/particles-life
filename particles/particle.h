#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include "../components/hitbox/hitboxSquare.h"

class Particle
{
    protected:
        sf::RenderWindow* window;
        sf::CircleShape* shape;

        HitboxSquare* hitbox;
        HitboxSquare* hitboxRange;

        int d, x ,y;

    public:
        enum class classParticle
        {
            RED
        };

        Particle(sf::RenderWindow* window, int d, int x, int y);
        ~Particle();

        virtual void update();
        virtual void render();
};

#endif