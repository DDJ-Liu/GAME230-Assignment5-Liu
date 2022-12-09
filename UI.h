#ifndef UI_H
#define UI_H
#include "GameVariableSettings.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

namespace gm {
	class UI
	{
	protected:
		sf::Font font;
		sf::Text scoreUI[MAX_PLAYER_NUMBER];
		sf::Text mainText;
		sf::Text subText;
	public:
		UI();
		void Update(sf::RenderWindow& window, float deltaTime, Player player[]);
		void Render(sf::RenderWindow& window, float deltaTime);
		void Scored(sf::RenderWindow& window, int playerID);
		void Winning(sf::RenderWindow& window, int playerID);
		~UI();
	};
}
#endif // !UI_H