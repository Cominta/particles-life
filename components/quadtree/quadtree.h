#ifndef QUADTREE_H
#define QUADTREE_H

#include "point.h"
#include <vector>

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
        sf::RenderWindow* window;
        std::vector<Point*> points;

        Quadtree* lt; // left-top
        Quadtree* rt; // right-top
        Quadtree* rb; // right-bottom
        Quadtree* lb; // left-bottom

    public:
        Quadtree(sf::RenderWindow* window, int size, float x, float y, float width, float height);
        ~Quadtree();

        bool intersects(Point* point);
        void insert(Point* point);
        void subdivide();
        void query(sf::RectangleShape* range, std::vector<Point*>& found);

        void update();
        void render();
};

#endif