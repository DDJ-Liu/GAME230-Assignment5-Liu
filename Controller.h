#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Paddle.h"
namespace gm {
	class Controller
	{
	public:
		enum PaddleDirection {
			vertical, horizontal
		};
		Controller(int id, Paddle& p, PaddleDirection pd);
		Controller();
		~Controller();
		virtual void update(sf::RenderWindow& window, float deltaTime) = 0;

	protected:
		int paddleId;
		Paddle* paddle;
		PaddleDirection direction;
	};
}
#endif
 