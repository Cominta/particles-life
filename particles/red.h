#ifndef RED_H
#define RED_H 

#include "particle.h"

class Red : public Particle
{
    private:
        int currentSpeedX;
        int currentSpeedY;
    
    public:
        Red(sf::RenderWindow* window, int d, int x, int y);
        ~Red();

        void update(float deltaTime, std::vector<Particle*> foundRange);
        void render();
};

#endif