#pragma once
#include <SFML/Graphics.hpp>
#include "MathGame.h"
#include "Constants.h"

namespace ApplesGame {
	struct Items {
		//Items data
		sf::RectangleShape BlackCubeShape;
		Position2D BlackCubePosition;

		sf::Sprite stoneSprite[NUM_STONE];
		Position2D stonePosition[NUM_STONE];

		sf::Sprite applesSprite[NUM_APPLES];
		Position2D applesPosition[NUM_APPLES];

	};

	struct Resurses;

	void InitGameItems(Items& item, const Resurses& texture);
}