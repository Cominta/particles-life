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
    this->updateMouse();

    if (mousePress)
    {
        Red* newParticle = new Red(this->window, 10, this->mousePosition.x, this->mousePosition.y);
        this->particles.emplace_back(newParticle);
        newParticle->update();
        this->quadtree->insert(newParticle->getHitbox());
    }

    for (auto &particle : this->particles)
    {
        particle->update();
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