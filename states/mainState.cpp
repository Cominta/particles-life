#include "mainState.h"

MainState::MainState(sf::RenderWindow* window)
    : State(window)
{
    this->margin = 160.0f; // с одной из сторон
    float thickness = 1.0f;
    float sizeX = this->window->getSize().x - this->margin * 2.0f;
    float sizeY = this->window->getSize().y - this->margin * 2.0f;
    this->statesClass = State::states::MAINSTATE;

    this->frame[0] = new sf::RectangleShape(sf::Vector2f(thickness, sizeY)); // левая сторона
    this->frame[0]->setOrigin(thickness / 2, sizeY / (this->margin * 2) / 2);
    this->frame[0]->setPosition(this->margin, this->margin + 2); // ТУТ ПЛЮС 2 ПИКСЕЛЯ ПОТОМУ ЧТО ОНО ПОЧЕМУ-ТО ЧУТЬ-ЧУТЬ ТОРЧАЛО, ЭТО БЕСИЛО!!!!!

    this->frame[1] = new sf::RectangleShape(sf::Vector2f(sizeX, thickness)); // верхняя сторона
    this->frame[1]->setOrigin(sizeX / (this->margin * 2) / 2, thickness / 2);
    this->frame[1]->setPosition(this->margin, this->margin);

    this->frame[2] = new sf::RectangleShape(sf::Vector2f(thickness, sizeY)); // правая сторона
    this->frame[2]->setOrigin(thickness / 2, sizeY / (this->margin * 2) / 2);
    this->frame[2]->setPosition(this->window->getSize().x - this->margin, this->margin + 2); // ТУТ ТОЖЕ!!!!!!

    this->frame[3] = new sf::RectangleShape(sf::Vector2f(sizeX, thickness)); // нижняя сторона
    this->frame[3]->setOrigin(sizeX / (this->margin * 2) / 2, thickness / 2);
    this->frame[3]->setPosition(this->margin, this->window->getSize().y - this->margin);
    
    this->objects.push_back(new Square(this->window, 100, 100, sf::Color::White, this->window->getSize().x / 2, this->window->getSize().y / 2));
}

MainState::~MainState()
{

}

void MainState::update(float deltaTime, bool mousePress)
{
    this->updateMouse();

    if (mousePress && 
        this->mousePosition.x > margin &&
        this->mousePosition.x < this->window->getSize().x - margin &&
        this->mousePosition.y > margin &&
        this->mousePosition.y < this->window->getSize().y - margin)
    {
        this->objects.push_back(new Square(this->window, 100, 100, sf::Color::White, this->mousePosition.x, this->mousePosition.y));
    }

    for (auto& object : this->objects)
    {
        object->update(deltaTime, this->frame);
    }
}

void MainState::render()
{
    for (sf::RectangleShape*& line : this->frame)
    {
        this->window->draw(*line);
    }

    for (auto& object : this->objects)
    {
        object->render();
    }
}