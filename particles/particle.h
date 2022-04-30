#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle
{
    private:
        

    public:
        enum class classParticle
        {
            RED
        };

        Particle();
        ~Particle();

        virtual void update();
        virtual void render();
};

#endif