#include "quadtree.h"

Quadtree::Quadtree(sf::RenderWindow* window, int size, float x, float y, float width, float height)
    : window(window), size(size), x(x), y(y), width(width), height(height)
{
    this->boundary = new HitboxSquare(window, this->width, this->height);
    this->boundary->setPosition(this->x, this->y);

    this->divided = false;
}

Quadtree::~Quadtree()
{

}

void Quadtree::clear()
{
    this->particles.clear();
    this->divided = false;

    this->lt = nullptr;
    this->rt = nullptr;
    this->rb = nullptr;
    this->lb = nullptr;
}

void Quadtree::insert(Particle* particle)
{
    if (!this->boundary->intersects(particle->getHitbox())) // AABB
    {
        return;
    }

    if (this->particles.size() < this->size)
    {
        this->particles.emplace_back(particle);
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

        this->lt->insert(particle);
        this->rt->insert(particle);
        this->rb->insert(particle);
        this->lb->insert(particle);
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

void Quadtree::query(HitboxSquare* range, std::vector<Particle*>& found)
{
    if (!this->boundary->intersects(range))
    {
        return;
    }

    else
    {
        for (auto &point : this->particles)
        {
            if (range->intersects(point->getHitbox()))
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
    this->boundary->render();

    if (divided)
    {
        this->lt->render();
        this->rt->render();
        this->rb->render();
        this->lb->render();
    }
}