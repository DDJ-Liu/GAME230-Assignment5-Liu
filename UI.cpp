#include "UI.h"

using namespace gm;
using namespace sf;

UI::UI() {
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	for (int i = 0; i < MAX_PLAYER_NUMBER; i++) {
		scoreUI[i].setFont(font);
		scoreUI[i].setCharacterSize(28);
		scoreUI[i].setStyle(Text::Style::Bold);
	}

	mainText.setFont(font);
	mainText.setCharacterSize(32);
	mainText.setPosition(GameWidth / 2, GameHeight / 2);
	subText.setFont(font);
	subText.setCharacterSize(28);

	scoreUI[0].setPosition(80, GameHeight / 2);
	scoreUI[1].setPosition(GameWidth - 80, GameHeight / 2);
	scoreUI[2].setPosition(GameWidth / 2, GameHeight - 80);
	scoreUI[3].setPosition(GameWidth / 2, 80);


}

void UI::Update(sf::RenderWindow& window, float deltaTime, Player player[]) {
	for (int i = 0; i < MAX_PLAYER_NUMBER; i++) {
		if (player[i].isActive()) {
			scoreUI[i].setString(std::to_string(player[i].getScore()));
		}
		else {
			scoreUI[i].setString("");
		}
	}
}

void UI::Render(sf::RenderWindow& window, float deltaTime) {
	for (int i = 0; i < MAX_PLAYER_NUMBER; i++) {
		window.draw(scoreUI[i]);
	}
}

void UI::Scored(sf::RenderWindow& window, int playerID) {
	window.clear();
	String s = "Player " + std::to_string(playerID) + " scores!";
	mainText.setPosition(GameWidth / 2 - 100, GameHeight / 2 - 30);
	mainText.setString(s);
	window.draw(mainText);
	window.display();
	mainText.setString("");
}

void UI::Winning(sf::RenderWindow& window, int playerID) {
	window.clear();
	String s = "Player " + std::to_string(playerID) + " reaches " + std::to_string(WINNING_GOALS) + " and wins the game!";
	String s2 = "press [Spacebar] to Restart.";
	mainText.setPosition(GameWidth / 2 - 270, GameHeight / 2 - 30);
	subText.setPosition(GameWidth / 2 - 180, GameHeight / 2 + 30);
	mainText.setString(s);
	subText.setString(s2);
	window.draw(mainText);
	window.draw(subText);
	window.display();
	mainText.setString("");
	subText.setString("");
}

UI::~UI() {
//	delete [] scoreUI;
}