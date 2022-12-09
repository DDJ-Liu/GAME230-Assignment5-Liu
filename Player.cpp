#include "Player.h"

using namespace sf;
using namespace gm;

Player::Player(int i, Paddle& p, sf::Keyboard::Key k1, sf::Keyboard::Key k2, Controller::PaddleDirection pd, bool ai, AIType aitype) : id(i), playerController(i, p, k1, k2, pd), aiController(i, p, pd, ai, aitype),aiControlled(ai) {
	score = 0;
	active = true;
}
Player::Player(){}

Player::~Player() {
	active = false;
	score = 0;
}
void Player::update(sf::RenderWindow& window, float deltaTime) {
	if (!aiControlled) {
		playerController.update(window, deltaTime);
	}
	else {
		aiController.update(window, deltaTime);
	}
}
int Player::getScore()const {
	return score;
}

void Player::handleInput(Event event) {
	if (!aiControlled) {
		playerController.handleInput(event);
	}
}


void Player::scored() {
	score++;
}

void Player::setAI(bool ai) {
	aiControlled = ai;
	aiController.setEnabled(ai);
}

void Player::setActive(bool b) {
	active = b;
}

bool Player::isActive() {
	return active;
}

AIController* Player::getAI() {
	return &aiController;
}

void Player::resetScore() {
	score = 0;
}

