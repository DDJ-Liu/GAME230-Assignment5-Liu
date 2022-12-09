#include "SoundManager.h"
#include <iostream>

using namespace gm;
using namespace sf;

SoundManager::SoundManager() {
    if (!sfxBuffer[BounceWall].loadFromFile("SFX/BounceAtWall.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    if (!sfxBuffer[BouncePaddle].loadFromFile("SFX/BounceAtPaddle.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    if (!sfxBuffer[Scored].loadFromFile("SFX/Scored.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    if (!sfxBuffer[Winning].loadFromFile("SFX/Winning.wav")) {
        std::cout << "Error loading sfx!" << std::endl;
    }
    for (int i = 0; i < 4; i++) {
        sfx[i].setBuffer(sfxBuffer[i]);
    }

}

SoundManager::~SoundManager() {

}

void SoundManager::playSFX(soundType sound) {
    sfx[sound].play();
}