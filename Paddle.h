#ifndef PADDLE_H
#define PADDLE_H
#include "Box.h"

namespace gm {
    class Paddle :
        public Box
    {
    protected:
        bool active=false;
        int id=0;
        Border border = gm::NoBorder;

    public:
        Paddle(int i, Border b, const sf::Vector2f& position, const sf::Vector2f& size);
        Paddle();
        ~Paddle();
        bool isActive()const;
        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void move(const sf::Vector2f& velocity) override;

        Border getBorder()const;

    };
}

#endif
