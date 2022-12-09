#include "AIController.h"

using namespace gm;
using namespace sf;

AIController::AIController(int id, Paddle& p, PaddleDirection pd, bool ai, AIType aiType) :Controller(id, p, pd), enabled(ai), type(aiType) {
	balls = nullptr;
	oppostiePaddle = nullptr;
	AItimer = AIinterval;
}

AIController::AIController(){}

AIController::~AIController() {
	paddle = nullptr;
	enabled = false;
	balls = nullptr;
	oppostiePaddle = nullptr;
}

void AIController::setSensor(Ball& ballList, Paddle& paddle) {
	balls = &ballList;
	oppostiePaddle = &paddle;
}



void AIController::update(sf::RenderWindow& window, float deltaTime) {
	if (enabled) {
		paddle->update(window, deltaTime);
		AItimer -= deltaTime;
		//std::cout << AItimer << std::endl;
		if (AItimer < 0) {
			paddle->setMovmentDirection(sense());
			AItimer = AIinterval;
		}
	}
}

MovementDirection AIController::sense() {
	switch (type)
	{
	case gm::simple:
		if (direction == vertical) {
			float ballY = balls->getPosition().y + originalSize;
			float paddleY = paddle->getPosition().y + PADDLE_LENGTH / 2;
			if (ballY + PlayerMovementSpeedPerSecond*AIinterval/3 < paddleY) {
				return Up;
			}
			if (ballY - PlayerMovementSpeedPerSecond * AIinterval/3 > paddleY) {
				return Down;
			}
			return None;
		}
		break;
	case gm::advanced:
		break;
	default:
		break;
	}

	return None;
}
bool AIController::isEnabled()const {
	return enabled;
}
void AIController::setEnabled(bool e) {
	enabled = e;
}
void AIController::setAiType(AIType t) {
	type = t;
}
