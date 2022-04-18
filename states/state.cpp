#include "state.h"

State::State(sf::RenderWindow* window)
    : window(window)
{

}

State::~State()
{

}

void State::update()
{

}

void State::update(float deltaTime, bool mousePress)
{
    
}

void State::render()
{

}

void State::updateMouse()
{   
    this->mousePosition = this->window->mapPixelToCoords(sf::Mouse::getPosition(*(this->window)));
}