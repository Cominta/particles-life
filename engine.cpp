#include "engine.h"

Engine::Engine()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1000, 700), "Hitbox Prototype");
    this->states.push(new MainState(this->window));
}

Engine::~Engine()
{

}

void Engine::update()
{
    this->updateSFML();

    if (!this->states.empty())
    {
        this->states.top()->update();
    }
}

void Engine::updateSFML()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Engine::render()
{
    this->window->clear();

    if (!this->states.empty())
    {
        this->states.top()->render();
    }

    this->window->display();
}

void Engine::start()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}