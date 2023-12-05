#pragma once
#include <SFML/Graphics.hpp>

namespace ApplesGame {
	struct Time {
		//time
		sf::Clock gameClock;
		float lastTime = 0.f;
		float currentTime = 0.f;
		float deltaTime = 0.f;

		//Score
		int bestScore = 0;
		int numEatenApples = 0;
	};
}