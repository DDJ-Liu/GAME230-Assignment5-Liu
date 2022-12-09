#ifndef BALL_H
#define BALL_H
#include "GameObject.h"
#include "Paddle.h"
#include <iostream>

namespace gm {
    const float originalSize = 10;
    const float originalSpeedPerSecond = 200;

    class Ball :
        public GameObject
    {
    protected:
        sf::CircleShape body;
        sf::Vector2f velocity;

    public:
        Ball(const sf::Vector2f position, const float size = originalSize, const float speed = originalSpeedPerSecond);
        void update(sf::RenderWindow& window, float deltatime) override;
        void render(sf::RenderWindow& window, float deltatime) override;
        void setPosition(const sf::Vector2f& position) override;
        void move(const sf::Vector2f& velocity) override;
        sf::Vector2f getVelocity() const;
        void setVelocity(const sf::Vector2f& velocity);
        void bounceAtWall(Border border);
        void bounceAtPeddal(const Paddle& paddle);
        const sf::Color& getFillColor() const;
        void setFillColor(const sf::Color& color);
        void reset(sf::RenderWindow& window);
        Border hitBorder(const sf::RenderWindow& window);
        ~Ball();
    };


}

#endif