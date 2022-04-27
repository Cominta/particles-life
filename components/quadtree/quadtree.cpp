#include "quadtree.h"

Quadtree::Quadtree(int size, float x, float y, float width, float height)
    : size(size), x(x), y(y), width(width), height(height)
{
    this->boundary = new sf::RectangleShape(sf::Vector2f(this->width, this->height));
    this->boundary->setOrigin(this->width / 2, this->height / 2);

    this->divided = false;
}

Quadtree::~Quadtree()
{

}

void Quadtree::insert(Point* point)
{
    if (!((*point).x >= this->x - this->width && (*point).x <= this->x + this->width &&
        (*point).y >= this->y - this->height && (*point).y <= this->y + this->height)) // AABB
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

            this->lt->insert(point);
            this->rt->insert(point);
            this->rb->insert(point);
            this->lb->insert(point);
        }
    }
    
    for (auto &p : this->points)
    {
        std::cout << (*p).x << " " << (*p).y << " point | ";
    }
    std::cout << "\n";
}

void Quadtree::subdivide()
{
    int newWidth = this->width / 2;
    int newHeight = this->height / 2;

    this->lt = new Quadtree(4, this->x - this->width / 2, this->y - this->height / 2, newWidth, newHeight);
    this->rt = new Quadtree(4, this->x + this->width / 2, this->y - this->height / 2, newWidth, newHeight);
    this->rb = new Quadtree(4, this->x + this->width / 2, this->y + this->height / 2, newWidth, newHeight);
    this->lb = new Quadtree(4, this->x - this->width / 2, this->y + this->height / 2, newWidth, newHeight);
}

void Quadtree::update()
{

}

void Quadtree::render()
{

}