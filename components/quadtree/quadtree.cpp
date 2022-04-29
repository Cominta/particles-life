#include "quadtree.h"

Quadtree::Quadtree(sf::RenderWindow* window, int size, float x, float y, float width, float height)
    : window(window), size(size), x(x), y(y), width(width), height(height)
{
    this->boundary = new sf::RectangleShape(sf::Vector2f(this->width, this->height));
    this->boundary->setPosition(this->x, this->y);
    this->boundary->setOrigin(this->width / 2, this->height / 2);
    this->boundary->setFillColor(sf::Color::Transparent);
    this->boundary->setOutlineColor(sf::Color::White);
    this->boundary->setOutlineThickness(1.0f);

    this->divided = false;
}

Quadtree::~Quadtree()
{

}


bool Quadtree::intersects(Point* point)
{
    return ((*point).x + (*point).width >= this->x - this->width / 2 && (*point).x - (*point).width <= this->x + this->width / 2 &&
        (*point).y + (*point).height >= this->y - this->height / 2 && (*point).y - (*point).height <= this->y + this->height / 2);
}

void Quadtree::insert(Point* point)
{
    if (!this->intersects(point)) // AABB
    {
        return;
    }

    if (this->points.size() < this->size)
    {
        this->points.emplace_back(point);
    }

    else
    {
        if (!divided)
        {
            this->subdivide();
            this->divided = true;

            // for (auto &point1 : this->points)
            // {
            //     this->lt->insert(point1);
            //     this->rt->insert(point1);
            //     this->rb->insert(point1);
            //     this->lb->insert(point1);
            // }

            // this->points.clear();
        }

        this->lt->insert(point);
        this->rt->insert(point);
        this->rb->insert(point);
        this->lb->insert(point);
    }
}

void Quadtree::subdivide()
{
    int newWidth = this->width / 2;
    int newHeight = this->height / 2;

    this->lt = new Quadtree(this->window, 4, this->x - this->width / 4, this->y - this->height / 4, newWidth, newHeight);
    this->rt = new Quadtree(this->window, 4, this->x + this->width / 4, this->y - this->height / 4, newWidth, newHeight);
    this->rb = new Quadtree(this->window, 4, this->x + this->width / 4, this->y + this->height / 4, newWidth, newHeight);
    this->lb = new Quadtree(this->window, 4, this->x - this->width / 4, this->y + this->height / 4, newWidth, newHeight);
}

void Quadtree::query(sf::RectangleShape* range, std::vector<Point*>& found)
{
    if (!this->boundary->getGlobalBounds().intersects(range->getGlobalBounds()))
    {
        return;
    }

    else
    {
        for (auto &point : this->points)
        {
            if (range->getGlobalBounds().intersects(point->r->getGlobalBounds()))
            {
                found.emplace_back(point);
            }
        }

        if (divided)
        {
            this->lt->query(range, found);
            this->rt->query(range, found);
            this->rb->query(range, found);
            this->lb->query(range, found);
        }
    }
}

void Quadtree::update()
{

}

void Quadtree::render()
{
    this->window->draw(*this->boundary);

    for (auto &point : this->points)
    {
        point->render();
    }

    if (divided)
    {
        this->lt->render();
        this->rt->render();
        this->rb->render();
        this->lb->render();
    }
}