#include "mainState.h"

MainState::MainState(sf::RenderWindow* window)
    : State(window)
{
    this->statesClass = State::states::MAINSTATE;

    this->quadtree = new Quadtree(this->window, 4, this->window->getSize().x / 2, this->window->getSize().y / 2, this->window->getSize().x, this->window->getSize().y);
    
    this->range = new sf::RectangleShape(sf::Vector2f(200, 200));
    this->range->setOrigin(100, 100);
    this->range->setFillColor(sf::Color::Transparent);
    this->range->setOutlineColor(sf::Color::Green);
    this->range->setOutlineThickness(1.0f);
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

    this->range->setPosition(this->mousePosition);

    this->found.clear();
    this->quadtree->query(range, this->found);

    for (auto &point : this->found)
    {
        point->r->setFillColor(sf::Color::Green);
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

    this->window->draw(*this->range);
    this->quadtree->render();
    
    for (auto &point : this->found)
    {
        point->r->setFillColor(sf::Color::White);
    }

}