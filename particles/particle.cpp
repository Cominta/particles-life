#include "particle.h"

Particle::Particle(sf::RenderWindow* window, int d, int x, int y)
    : window(window), d(d), x(x), y(y)
{

}

Particle::~Particle()
{
    
}

void Particle::update()
{

}

void Particle::update(float deltaTime, std::vector<Particle*> foundRange)
{

}

void Particle::render()
{

}