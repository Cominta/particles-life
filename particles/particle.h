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


    public:
        int d, x ,y;

        enum class particleClass
        {
            RED
        };
    
        particleClass classP;

        Particle(sf::RenderWindow* window, int d, int x, int y);
        ~Particle();

        virtual void update();
        virtual void update(float deltaTime, std::vector<Particle*> foundRange);
        virtual void render();

        HitboxSquare* getHitbox() {return this->hitbox;};
        HitboxSquare* getHitboxRange() {return this->hitboxRange;};
};

#endif