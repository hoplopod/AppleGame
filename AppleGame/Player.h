#pragma once
#include <SFML/Graphics.hpp>
#include "MathGame.h"
#include "Constants.h"

namespace ApplesGame {
	enum class PlayerDirection {
		Pause = -1,
		Right,
		Up,
		left,
		Down
	};

	struct Player {
		//Player data
		Position2D playerPosition;
		sf::Sprite playerSprite;
		float playerSpeed = INITIAL_SPEED;
		PlayerDirection playerDirection = PlayerDirection::Right;
	};

	struct Resurses;

	void InitGamePlayer(Player& player, const Resurses& texture);
}