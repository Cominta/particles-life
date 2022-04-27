#include "mainState.h"

MainState::MainState(sf::RenderWindow* window)
    : State(window)
{
    this->statesClass = State::states::MAINSTATE;

    this->quadtree = new Quadtree(4, 200, 200, 200, 200);

    for (int i = 0; i < 600; i++)
    {
        this->quadtree->insert(new Point(100 * i, 10 + i * 3));
    }
}

MainState::~MainState()
{

}

void MainState::update(float deltaTime, bool mousePress)
{
    this->updateMouse();

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
}