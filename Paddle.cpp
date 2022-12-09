#include "Paddle.h"

using namespace gm;
using namespace sf;

Paddle::Paddle(int i, Border b, const sf::Vector2f& position, const sf::Vector2f& size) :id(i), Box(position, size), border(b) {
	active = true;
	/*
	switch (b)
	{
	case gm::LeftBorder:
		Box::Box(Vector2f(PADDLE_BORDER_OFFSET, window.getSize().y - PADDLE_LENGTH / 2), Vector2f(PADDLE_WIDTH, PADDLE_LENGTH));
		break;
	case gm::RightBorder:
		Box::Box(Vector2f(window.getSize().x - PADDLE_BORDER_OFFSET - PADDLE_WIDTH, window.getSize().y - PADDLE_LENGTH / 2), Vector2f(PADDLE_WIDTH, PADDLE_LENGTH));
		break;
	case gm::BottomBorder:
		Box::Box(Vector2f(window.getSize().x - PADDLE_LENGTH / 2, window.getSize().y - PADDLE_BORDER_OFFSET - PADDLE_WIDTH), Vector2f(PADDLE_LENGTH, PADDLE_WIDTH));
		break;
	case gm::TopBorder:
		Box::Box(Vector2f(window.getSize().x - PADDLE_LENGTH / 2, PADDLE_BORDER_OFFSET), Vector2f(PADDLE_LENGTH, PADDLE_WIDTH));
		break;
	case gm::NoBorder:
	default:
		std::cout << "paddle construct error" << std::endl;
		break;
	}
	*/
}
Paddle::Paddle() {}

Paddle::~Paddle() {

}
bool Paddle::isActive()const {
	return active;
}


void Paddle::update(sf::RenderWindow& window, float deltaTime) {

	if ((collider.left <= 0 && direction == Left) ||
		((collider.left + collider.width >= window.getSize().x) && direction == Right) ||
		(collider.top <= 0 && direction == Up) ||
		((collider.top + collider.height) >= window.getSize().y) && direction == Down) {

	}
	else {
		Box::update(window, deltaTime);
	}
}

void Paddle::render(sf::RenderWindow& window, float deltaTime) {
	Box::render(window, deltaTime);
}

void Paddle::move(const sf::Vector2f& velocity) {
	Box::move(velocity);
}

Border Paddle::getBorder()const {
	return border;
}
