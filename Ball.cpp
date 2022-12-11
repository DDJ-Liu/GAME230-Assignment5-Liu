#include "Ball.h"

using namespace gm;
using namespace sf;

Ball::Ball(const sf::Vector2f position, const float size, const float speed):GameObject(position,Vector2f(2*size,2*size)) {
	body.setPosition(position);
	body.setRadius(size);
}
void Ball::update(sf::RenderWindow& window, float deltatime) {
	//move ball
	move(velocity * deltatime);
	//hit wall
	//	bounceAtWall(hitBorder(window));
	//hit paddle
}
void Ball::render(sf::RenderWindow& window, float deltatime) {
	window.draw(body);
}
void Ball::setPosition(const sf::Vector2f& position) {
	//
	GameObject::setPosition(position);
	body.setPosition(position);
}
void Ball::move(const sf::Vector2f& velocity) {
	//std::cout << "ball move" << std::endl;
	GameObject::move(velocity);
	body.setPosition(position);
}
Vector2f Ball::getVelocity() const {
	return velocity;
}
void Ball::setVelocity(const sf::Vector2f& velocity) {
	this->velocity = velocity;
}
void Ball::bounceAtWall(Border border) {
	switch (border)
	{
	case gm::NoBorder:
		return;
	case gm::LeftBorder:
//		std::cout << "Left Wall bounce" << std::endl;
	case gm::RightBorder:
//		std::cout << "Right Wall bounce" << std::endl;
		velocity.x *= -1;
		return;
	case gm::BottomBorder:
//		std::cout << "Bottom Wall bounce" << std::endl;
	case gm::TopBorder:
//		std::cout << "Top Wall bounce" << std::endl;
		velocity.y *= -1;
		return;
	default:
		std::cout << "Wall bounce error" << std::endl;
		break;
	}
}
void Ball::bounceAtPeddal(const Paddle& paddle) {
	switch (paddle.getBorder())
	{
	case LeftBorder:
	case RightBorder:
		velocity.x *= -(1 + VELOCITY_AMPLIFIER);
		if (paddle.getMovementDirection() == Up) {
			velocity.y -= VELOCITY_FIXED_CHANGE_AMOUNT;
		}
		else if (paddle.getMovementDirection() == Down) {
			velocity.y += VELOCITY_FIXED_CHANGE_AMOUNT;
		}
		break;
	case BottomBorder:
	case TopBorder:
		velocity.y *= -(1 + VELOCITY_AMPLIFIER);
		if (paddle.getMovementDirection() == Left) {
			velocity.x -= VELOCITY_FIXED_CHANGE_AMOUNT;
		}
		else if (paddle.getMovementDirection() == Right) {
			velocity.x += VELOCITY_FIXED_CHANGE_AMOUNT;
		}
		break;
	default:
		break;
	}

}
const sf::Color& Ball::getFillColor() const {
	return body.getFillColor();
}
void Ball::setFillColor(const sf::Color& color) {
	body.setFillColor(color);
}
void Ball::reset(RenderWindow& window) {
//set position to middle	
	int width = window.getSize().x;
	int height = window.getSize().y;
	setPosition(Vector2f(width/2-body.getRadius(),height/2-body.getRadius()));
//set velocity to random direction
	Vector2f direction = Vector2f(gm::Randf(0., 1.), gm::Randf(0., 1.));
	velocity = originalSpeedPerSecond * vectorNormalize(direction);
}

Border Ball::hitBorder(const RenderWindow& window) {
	int width = window.getSize().x;
	int height = window.getSize().y;
	if (position.x <= 0) {
		return LeftBorder;
	}
	if (position.y <= 0) {
		return TopBorder;
	}
	if (position.x + body.getRadius() * 2 >= width) {
		return RightBorder;
	}
	if (position.y + body.getRadius() * 2 >= height) {
		return BottomBorder;
	}
	return NoBorder;
}

Ball::~Ball() {

}
