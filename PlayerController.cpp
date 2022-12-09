#include "PlayerController.h"

using namespace gm;
using namespace sf;

PlayerController::PlayerController(int id, Paddle& p, sf::Keyboard::Key k1, sf::Keyboard::Key k2, PaddleDirection pd) :Controller(id, p, pd), key1(k1), key2(k2) {

}
PlayerController::PlayerController() {

}

PlayerController::~PlayerController() {
	paddle = nullptr;
}
void PlayerController::update(sf::RenderWindow& window, float deltaTime) {
	paddle->update(window, deltaTime);
}

void PlayerController::handleInput(Event event) {
	if (event.type == Event::KeyPressed) {
		if (event.key.code == key1) {
			if (direction == horizontal) {
				paddle->setMovmentDirection(MovementDirection::Left);
			}
			else {
				paddle->setMovmentDirection(MovementDirection::Up);
			}
		}
		else if (event.key.code == key2) {
			if (direction == horizontal) {
				paddle->setMovmentDirection(MovementDirection::Right);
			}
			else {
				paddle->setMovmentDirection(MovementDirection::Down);
			}
		}
	}

	if (event.type == Event::KeyReleased) {
		if (event.key.code == key1 && (paddle->getMovementDirection() == MovementDirection::Left || paddle->getMovementDirection() == MovementDirection::Up)) {
			paddle->setMovmentDirection(MovementDirection::None);
		}
		if (event.key.code == key2 && (paddle->getMovementDirection() == MovementDirection::Right || paddle->getMovementDirection() == MovementDirection::Down)) {
			paddle->setMovmentDirection(MovementDirection::None);
		}
	}
}