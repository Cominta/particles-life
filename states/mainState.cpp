#include "mainState.h"

MainState::MainState(sf::RenderWindow* window)
    : State(window)
{
    float width = 700.0f;
    float height = 400.0f;
    float thickness = 1.0f;

    this->frame[0] = new sf::RectangleShape(sf::Vector2f(thickness, height)); // левая сторона


    this->frame[1] = new sf::RectangleShape(sf::Vector2f(width, thickness)); // верхняя сторона


    this->frame[2] = new sf::RectangleShape(sf::Vector2f(thickness, height)); // правая сторона
    this->frame[2]->setOrigin(thickness / 2, width / 2);
    this->frame[2]->setPosition(this->window->getSize().x - width / 2, this->window->getSize().y - 200);


    this->frame[3] = new sf::RectangleShape(sf::Vector2f(width, thickness)); // нижняя сторона
    this->frame[3]->setOrigin(width / 2, thickness / 2);
    this->frame[3]->setPosition(this->window->getSize().x / 2, this->window->getSize().y - height / 2 + 50);


    this->c->setOrigin(5.0f, 5.0f);
    this->c->setPosition(150, 350);
}

MainState::~MainState()
{

}

void MainState::update()
{
    
}

void MainState::render()
{
    for (sf::RectangleShape*& line : this->frame)
    {
        this->window->draw(*line);
    }

    this->window->draw(*this->c);
}