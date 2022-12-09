// Our include guards
// These are critical for preventing collision related errors from a file accidentally getting fully included multiple times
#ifndef GAME_H
#define GAME_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

 /* STL Includes */
#include <iostream>

 /* Our Includes */
#include "Box.h"
#include "Ball.h"
#include "Player.h"
#include "UI.h"
#include "SoundManager.h"

// Place our classes, functions, variables, and so forth in their own namespace to avoid naming collisions
namespace gm {

	const sf::Keyboard::Key CONTROLLING_KEYS[4][2] = {
	{sf::Keyboard::W,sf::Keyboard::S},
	{sf::Keyboard::Up,sf::Keyboard::Down},
	{sf::Keyboard::G,sf::Keyboard::H},
	{sf::Keyboard::K,sf::Keyboard::L}
	};
	/* Our Game Class                               *
	 * Implements the Game Loop Programming Pattern */
	class Game {
	private:
		// The game window
		sf::RenderWindow window;
		// For tracking/maintaining delta time
		sf::Clock clock;
		float deltaTime;
		UI ui;
		SoundManager soundManager;
		// Our game objects
		//Box box1;
		//Box box2;
		Ball ball1;
		int playerNum = 2;
		Paddle paddle[MAX_PLAYER_NUMBER];
		Player player[MAX_PLAYER_NUMBER];
		float pauseTimer = 0;
		bool endGame = false;
	public:
		/* Protoypes */
		// Constructor
		Game();
		// Will start and manage the game loop programming pattern
		void run();
		// Game Loop Programming Pattern Methods
		void handleInput();
		void update();
		void render();
		void initialize();
		void pause(float pauseTime);
		void goal(int playerID);
		void reset();
		void restart();
		// Destructor
		~Game();
	};

}

#endif