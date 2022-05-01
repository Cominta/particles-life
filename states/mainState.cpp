#include "mainState.h"

MainState::MainState(sf::RenderWindow* window)
    : State(window)
{
    this->statesClass = State::states::MAINSTATE;

    this->quadtree = new Quadtree(this->window, 4, this->window->getSize().x / 2, this->window->getSize().y / 2, this->window->getSize().x, this->window->getSize().y);
}

MainState::~MainState()
{

}

void MainState::update(float deltaTime, bool mousePress)
{
    this->quadtree->clear();

    this->updateMouse();

    for (auto &particle : this->particles)
    {
        this->quadtree->insert(particle);
    }

    for (auto &particle : this->particles)
    {
        std::vector<Particle*> foundRange;
        this->quadtree->query(particle->getHitboxRange(), foundRange);
        particle->update(deltaTime, foundRange);
    }

    if (mousePress)
    {
        Red* newParticle = new Red(this->window, 10, this->mousePosition.x, this->mousePosition.y);
        this->particles.emplace_back(newParticle);

        std::vector<Particle*> foundRange;
        this->quadtree->query(newParticle->getHitboxRange(), foundRange);
        newParticle->update(deltaTime, foundRange);
        this->quadtree->insert(newParticle);
    }
}

void MainState::render()
{
    this->quadtree->render();
    
    for (auto &particle : this->particles)
    {
        particle->render();
    }
}