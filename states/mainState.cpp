#include "mainState.h"

MainState::MainState(sf::RenderWindow* window)
    : State(window)
{
    float margin = 160.0f; // с одной из сторон
    float thickness = 1.0f;
    float sizeX = this->window->getSize().x - margin * 2.0f;
    float sizeY = this->window->getSize().y - margin * 2.0f;
    this->statesClass = State::states::MAINSTATE;

    this->frame[0] = new sf::RectangleShape(sf::Vector2f(thickness, sizeY)); // левая сторона
    this->frame[0]->setOrigin(thickness / 2, sizeY / (margin * 2) / 2);
    this->frame[0]->setPosition(margin, margin + 2); // ТУТ ПЛЮС 2 ПИКСЕЛЯ ПОТОМУ ЧТО ОНО ПОЧЕМУ-ТО ЧУТЬ-ЧУТЬ ТОРЧАЛО, ЭТО БЕСИЛО!!!!!

    this->frame[1] = new sf::RectangleShape(sf::Vector2f(sizeX, thickness)); // верхняя сторона
    this->frame[1]->setOrigin(sizeX / (margin * 2) / 2, thickness / 2);
    this->frame[1]->setPosition(margin, margin);

    this->frame[2] = new sf::RectangleShape(sf::Vector2f(thickness, sizeY)); // правая сторона
    this->frame[2]->setOrigin(thickness / 2, sizeY / (margin * 2) / 2);
    this->frame[2]->setPosition(this->window->getSize().x - margin, margin + 2); // ТУТ ТОЖЕ!!!!!!

    this->frame[3] = new sf::RectangleShape(sf::Vector2f(sizeX, thickness)); // нижняя сторона
    this->frame[3]->setOrigin(sizeX / (margin * 2) / 2, thickness / 2);
    this->frame[3]->setPosition(margin, this->window->getSize().y - margin);
    
    this->square = new Square(this->window, 100, 100, sf::Color::White, this->window->getSize().x / 2, this->window->getSize().y / 2);
}

MainState::~MainState()
{

}

void MainState::update(float deltaTime)
{
    this->square->update(deltaTime);

    // проверка на выход за рамку
    if (this->frame[3]->getGlobalBounds().intersects(this->square->getShape()->getGlobalBounds()))
    {
        this->square->setPosition(this->square->getPosition().x, this->frame[3]->getPosition().y - this->square->getSize().y / 2);
    }
}

void MainState::render()
{
    for (sf::RectangleShape*& line : this->frame)
    {
        this->window->draw(*line);
    }

    this->square->render();
}