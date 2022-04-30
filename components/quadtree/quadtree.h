#ifndef QUADTREE_H
#define QUADTREE_H

#include "../hitbox/hitboxSquare.h"
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

        HitboxSquare* boundary;
        sf::RenderWindow* window;
        std::vector<HitboxSquare*> points;

        Quadtree* lt; // left-top
        Quadtree* rt; // right-top
        Quadtree* rb; // right-bottom
        Quadtree* lb; // left-bottom

    public:
        Quadtree(sf::RenderWindow* window, int size, float x, float y, float width, float height);
        ~Quadtree();

        void insert(HitboxSquare* point);
        void subdivide();
        void query(HitboxSquare* range, std::vector<HitboxSquare*>& found);

        void update();
        void render();
};

#endif