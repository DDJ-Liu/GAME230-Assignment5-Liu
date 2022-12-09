#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <SFML/Audio.hpp>
namespace gm {

	class SoundManager
	{
	private:
		sf::SoundBuffer sfxBuffer[4];
		sf::Sound sfx[4];
	public:
		SoundManager();
		~SoundManager();
		enum soundType {
			BounceWall = 0,
			BouncePaddle = 1,
			Scored = 2,
			Winning = 3
		};
		void playSFX(soundType sound);
	};
}
#endif // !SOUNDMANAGER_H