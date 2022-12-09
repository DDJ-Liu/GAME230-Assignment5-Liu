#ifndef BOX_H
#define BOX_H

#include "GameObject.h"

namespace gm {

    class Box :
        public GameObject
    {
    protected:
        sf::RectangleShape body;
        MovementDirection direction;
    public:
        Box(const sf::Vector2f& position, const sf::Vector2f& size);

        Box();

        virtual void update(sf::RenderWindow& window, float deltaTime) override;

        virtual void render(sf::RenderWindow& window, float deltaTime) override;

        virtual void setPosition(const sf::Vector2f& position) override;

        // Move the box from its current position to a new one with a specified velocity
        virtual void move(const sf::Vector2f& velocity) override;

        virtual void setMovmentDirection(MovementDirection direction);

        virtual MovementDirection getMovementDirection() const;

        const sf::Color& getFillColor() const;

        void setFillColor(const sf::Color& color);
    };
}

#endif