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
        this->quadtree->insert(new Point(this->window, this->mousePosition.x, this->mousePosition.y));
    }

    for (auto& object : this->objects)
    {
        object->update(deltaTime);
    }
}

void MainState::render()
{
    for (auto& object : this->objects)
    {
        object->render();
    }

    this->quadtree->render();
}