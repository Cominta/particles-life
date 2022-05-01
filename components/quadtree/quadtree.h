#ifndef QUADTREE_H
#define QUADTREE_H

#include "../hitbox/hitboxSquare.h"
#include "../../particles/particle.h"
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
        std::vector<Particle*> particles;

        Quadtree* lt; // left-top
        Quadtree* rt; // right-top
        Quadtree* rb; // right-bottom
        Quadtree* lb; // left-bottom

    public:
        Quadtree(sf::RenderWindow* window, int size, float x, float y, float width, float height);
        ~Quadtree();

        void clear();
        void insert(Particle* particle);
        void subdivide();
        void query(HitboxSquare* range, std::vector<Particle*>& found);

        void update();
        void render();
};

#endif