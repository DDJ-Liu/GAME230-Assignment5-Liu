// We need to include our header file to implement the function prototypes of our Game class
#include "Game.h"

// Since we are in our private .cpp file, it's fine to use a namespace here
using namespace gm;
using namespace sf;

// Implement constructor, this will effectively be a setup function as the game gets more complex
Game::Game() : window(VideoMode(GameWidth, GameHeight), "Game"), clock(), deltaTime(0), /*box1(Vector2f(250, 300), Vector2f(50, 50)), box2(Vector2f(350, 300), Vector2f(50, 50)),*/ ball1(Vector2f(300, 300)),ui(), endGame(false), soundManager() {
	// Set our fps to 60
	window.setFramerateLimit(60);
}

void Game::run() {
	// This is our game loop!
	// All input, logic, and rendering should be handled here
	initialize();
	while (window.isOpen())
	{
		// Every frame we...
		// Keep track of the delta time for smoother movement
		deltaTime = clock.restart().asSeconds();
		//std::cout << deltaTime << std::endl;
		// Handle input first...
		handleInput();

		// Then update...
		update();

		// Then render...
		render();
	}
}

// Implements the handle input portion of our Game Loop Programming Pattern
void Game::handleInput() {
	// Check for events from the window
	// E.g., is the window being closed?
	Event event;
	while (window.pollEvent(event))
	{
		if(pauseTimer>0){
		//handle input during pause(restart when endgame)
			if (endGame) {
				if (event.type == Event::KeyPressed) {
					if (event.key.code == Keyboard::Space) {
						restart();
						endGame = false;
					}
				}
			}
		}
		else {
			if (event.type == Event::Closed)
				window.close();

			for (int i = 0; i < playerNum; i++) {
				if (player[i].isActive()) {
					player[i].handleInput(event);
				}
			}
		}
		/*
		// Handle keyboard input to move box 1
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Left) {
				box1.setMovmentDirection(MovementDirection::Left);
			}else if (event.key.code == Keyboard::Right) {
				box1.setMovmentDirection(MovementDirection::Right);
			}
		}

		if (event.type == Event::KeyReleased) {
			if (event.key.code == Keyboard::Left && box1.getMovementDirection() == MovementDirection::Left) {
				box1.setMovmentDirection(MovementDirection::None);
			}
			if (event.key.code == Keyboard::Right && box1.getMovementDirection() == MovementDirection::Right) {
				box1.setMovmentDirection(MovementDirection::None);
			}
		}
		*/
	}
}

// Implements the update portion of our Game Loop Programming Pattern
void Game::update() {
	//if pause
	if (pauseTimer > 0) {
		pauseTimer -= deltaTime;
//		std::cout << pauseTimer << std::endl;
	}
	else {
		//ball update
		ball1.update(window, deltaTime);
		//hit border
		if (ball1.hitBorder(window) != NoBorder) {
			ball1.bounceAtWall(ball1.hitBorder(window));
			switch (ball1.hitBorder(window))
			{
			case Border::LeftBorder:
				//player2 score
				if (player[1].isActive()) {
					goal(2);
				}
				else {
					soundManager.playSFX(SoundManager::BounceWall);
				}
				break;
			case Border::RightBorder:
				//player1 score
				if (player[0].isActive()) {
					goal(1);
				}
				else {
					soundManager.playSFX(SoundManager::BounceWall);
				}
				break;
			case Border::TopBorder:
				if (player[2].isActive()) {
					goal(3);
				}
				else {
					soundManager.playSFX(SoundManager::BounceWall);
				}
			case Border::BottomBorder:
				if (player[3].isActive()) {
					goal(4);
				}
				else {
					soundManager.playSFX(SoundManager::BounceWall);
				}
			default:
				break;
			}
		}
		//hit paddle
		for (int i = 0; i < playerNum; i++) {
			if (ball1.collide(paddle[i].getCollider())) {
				ball1.bounceAtPeddal(paddle[i]);
				soundManager.playSFX(SoundManager::BouncePaddle);
			}
		}

		//player(AI & paddle) update
		for (int i = 0; i < playerNum; i++) {
			if (player[i].isActive()) {
				player[i].update(window, deltaTime);
			}
		}

		ui.Update(window, deltaTime, player);
	}
	// Update our boxes (i.e., move them based on the block's specified movement direction)
	/*
	box1.update(window, deltaTime);
	box2.update(window, deltaTime);


	// If the mouse has entered box 1 then color it green
	if (box1.collide(Vector2f(Mouse::getPosition(window)))) {
		box1.setFillColor(Color::Green);
	} else {
		box1.setFillColor(Color::White);
	}

	// If the mouse has entered box 2 then color it green
	if (box2.collide(Vector2f(Mouse::getPosition(window)))) {
		box2.setFillColor(Color::Green);
	}
	else {
		box2.setFillColor(Color::White);
	}

	// If box 1 and 2 have collided then turn 1 blue and 2 red
	if (box2.collide(box1.getCollider())) {
		box1.setFillColor(Color::Blue);
		box2.setFillColor(Color::Red);
	}

	*/
}

// Implements the render portion of our Game Loop Programming Pattern
void Game::render() {
	if (pauseTimer > 0) {
		//pause time UI render(Score,endgame)
	}
	else {
		// This clears the window at the beginning of every frame
		window.clear();

		// Draw our boxes
		//box1.render(window, deltaTime);
		//box2.render(window, deltaTime);
		ball1.render(window, deltaTime);

		for (int i = 0; i < playerNum; i++) {
			if (player[i].isActive()) {
				paddle[i].render(window, deltaTime);
			}
		}

		ui.Render(window, deltaTime);
		// Display the window buffer for this frame
		window.display();
	}
}

void Game::initialize() {
	//ball
	ball1.reset(window);

	//paddles
	if (0 < MAX_PLAYER_NUMBER) {
		paddle[0] = Paddle(1,LeftBorder, Vector2f(PADDLE_BORDER_OFFSET, window.getSize().y/2 - PADDLE_LENGTH / 2), Vector2f(PADDLE_WIDTH, PADDLE_LENGTH));
	}
	if (1 < MAX_PLAYER_NUMBER) {
		paddle[1] = Paddle(2, RightBorder, Vector2f(window.getSize().x - PADDLE_BORDER_OFFSET - PADDLE_WIDTH, window.getSize().y/2 - PADDLE_LENGTH / 2), Vector2f(PADDLE_WIDTH, PADDLE_LENGTH));
	}
	if (2 < MAX_PLAYER_NUMBER) {
		paddle[2] = Paddle(3, BottomBorder, Vector2f(window.getSize().x/2 - PADDLE_LENGTH / 2, window.getSize().y - PADDLE_BORDER_OFFSET - PADDLE_WIDTH), Vector2f(PADDLE_LENGTH, PADDLE_WIDTH));
	}	
	if (3 < MAX_PLAYER_NUMBER) {
		paddle[3] = Paddle(4, TopBorder, Vector2f(window.getSize().x / 2 - PADDLE_LENGTH / 2, PADDLE_BORDER_OFFSET), Vector2f(PADDLE_LENGTH, PADDLE_WIDTH));
	}
	//players
	for (int i = 0; i < MAX_PLAYER_NUMBER; i++) {
		player[i] = Player(i + 1, paddle[i], CONTROLLING_KEYS[i][0], CONTROLLING_KEYS[i][1], (i < 2 ? Controller::vertical : Controller::horizontal), false, AIType::simple);
		player[i].setActive(false);
	}
	for (int i = 0; i < playerNum; i++) {
		player[i].setActive(true);
	}

	//AI setting
	player[0].getAI()->setSensor(ball1, paddle[1]);
	player[1].getAI()->setSensor(ball1, paddle[0]);

	//gamemode settings
	if (playerNum >= 2)
		player[1].setAI(true);

	pauseTimer;

}


// Implement destructor, make sure we free up any memory that we allocated here!
Game::~Game() {

}

void Game::pause(float pauseTime) {
	pauseTimer = pauseTime;
}
void Game::goal(int playerID) {
	if (player[playerID - 1].isActive()) {
		player[playerID - 1].scored();
		if (player[playerID - 1].getScore() >= WINNING_GOALS) {
			//endgame
			endGame = true;
			soundManager.playSFX(SoundManager::Winning);
			pause(ETERNAL_PAUSE_TIME);
			ui.Winning(window, playerID);
		}
		else {
			//pause and display score
			soundManager.playSFX(SoundManager::Scored);
			pause(SCORED_PAUSE_TIME);
			ui.Scored(window,playerID);
			reset();
		}
	}
}

void Game::reset() {
	ball1.reset(window);
	if (0 < MAX_PLAYER_NUMBER) {
		paddle[0].setPosition(Vector2f(PADDLE_BORDER_OFFSET, window.getSize().y / 2 - PADDLE_LENGTH / 2));
		paddle[0].setMovmentDirection(None);
	}
	if (1 < MAX_PLAYER_NUMBER) {
		paddle[1].setPosition(Vector2f(window.getSize().x - PADDLE_BORDER_OFFSET - PADDLE_WIDTH, window.getSize().y / 2 - PADDLE_LENGTH / 2));
		paddle[1].setMovmentDirection(None);
	}
	if (2 < MAX_PLAYER_NUMBER) {
		paddle[2].setPosition(Vector2f(window.getSize().x / 2 - PADDLE_LENGTH / 2, window.getSize().y - PADDLE_BORDER_OFFSET - PADDLE_WIDTH));
		paddle[2].setMovmentDirection(None);
	}
	if (3 < MAX_PLAYER_NUMBER) {
		paddle[3].setPosition(Vector2f(window.getSize().x / 2 - PADDLE_LENGTH / 2, PADDLE_BORDER_OFFSET));
		paddle[3].setMovmentDirection(None);
	}
}
void Game::restart() {
	reset();
	for (int i = 0; i < MAX_PLAYER_NUMBER; i++) {
		player[i].resetScore();
	}
	pauseTimer = 0;
}