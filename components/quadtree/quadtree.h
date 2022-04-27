#ifndef QUADTREE_H
#define QUADTREE_H

#include "point.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Quadtree
{
    private:
        int size;
        float x;
        float y;
        float width;
        float height;
        bool divided;

        sf::RectangleShape* boundary;
        std::vector<Point*> points;

        Quadtree* lt; // left-top
        Quadtree* rt; // right-top
        Quadtree* rb; // right-bottom
        Quadtree* lb; // left-bottom

    public:
        Quadtree(int size, float x, float y, float width, float height);
        ~Quadtree();

        void insert(Point* point);
        void subdivide();

        void update();
        void render();
};

#endif