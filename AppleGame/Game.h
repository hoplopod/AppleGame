#include <SFML/Audio.hpp>

#pragma once
#include "MathGame.h"
#include "Player.h"
#include "Constants.h"
#include "Items.h"
#include "Time.h"

namespace ApplesGame {

	void PlayerSpawnEffect(Time& time, Player& player,sf::RenderWindow& window, Items& item, Resurses& text);

	void Textures(Resurses& texture, Resurses& sound, Resurses& text);

	int GameCollide(Items& item, Player& player, Time& time, Resurses& sound);

	void MovePlayer(Items& item, Player& player, Time& time);

	void Fps(Items& item,sf::RenderWindow& window, Player& player, Resurses& text, Time& time);

	void DeinializeGame(Items& item, Player& player);

	struct Resurses {
		sf::Texture playerTexture;
		sf::Texture stoneTexture;
		sf::Texture applesTexture;
		
		sf::SoundBuffer PlayerDie;
		sf::SoundBuffer EatApple;

		sf::Sound Deth;
		sf::Sound Eat;

		sf::Font Arcada;
		sf::Text Score;
	};

}