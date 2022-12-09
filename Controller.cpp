#include "Controller.h"

using namespace gm;
using namespace sf;

Controller::Controller(int id, Paddle& p, PaddleDirection pd) :paddleId(id),direction(pd) {
	paddle = &p;
}
Controller::Controller() {};
Controller::~Controller() {
	paddle = nullptr;
}
