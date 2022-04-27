#include "engine.h"

Engine::Engine()
{
    this->delta = 0.0f;

    this->window = new sf::RenderWindow(sf::VideoMode(1100, 800), "Hitbox Prototype");
    this->states.push(new MainState(this->window));
}

Engine::~Engine()
{

}

void Engine::start()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Engine::update()
{
    this->updateSFML();
    this->updateDelta();

    if (!this->states.empty())
    {
        if (this->states.top()->statesClass == State::states::MAINSTATE)
        {
            this->states.top()->update(this->delta, this->mousePress);
        }

        this->states.top()->update();
    }

    this->mousePress = false;
}

void Engine::updateSFML()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
        {
            this->window->close();
        }

        else if (this->sfEvent.mouseButton.button == sf::Mouse::Button::Left && this->sfEvent.type == sf::Event::MouseButtonReleased)
        {
            this->mousePress = true;
        }
    }
}

void Engine::updateDelta()
{
    sf::Clock deltaClock;
    sf::Time deltaTime = deltaClock.restart();
    this->delta = deltaTime.asSeconds();
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