#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerController.h"
#include "AIController.h"


namespace gm {
	class Player
	{
	protected:
		int id = 0;
		int score = 0;
		bool aiControlled = false;
		bool active = false;
		PlayerController playerController;
		AIController aiController;
	public:
		Player(int i, Paddle& p, sf::Keyboard::Key k1, sf::Keyboard::Key k2, Controller::PaddleDirection pd, bool ai, AIType aitype);
		Player();
		~Player();
		void update(sf::RenderWindow& window, float deltaTime);
		void handleInput(sf::Event event);
		int getScore()const;
		void scored();
		void setAI(bool ai);
		void setActive(bool b);
		bool isActive();
		AIController* getAI();
		void resetScore();
//		Player& operator=(const Player& other);
	};
}

#endif