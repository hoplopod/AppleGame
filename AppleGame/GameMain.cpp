// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game.h"

using namespace ApplesGame;

int main()
{
	int seed = (int)time(nullptr);
	srand(seed);

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ApplesGame");

	Player player;

	Time time;

	Items item;

	Resurses texture, sound, text;

	Textures(texture, sound, text);

	InitGamePlayer(player, texture);
	
	while (window.isOpen()) {

		InitGameItems(item, texture);

		DeinializeGame(item, player);
		
		Fps(item, window, player, text, time);

		PlayerSpawnEffect(time, player, window, item, text);

		while (window.isOpen())
		{
			sf::sleep(sf::milliseconds(16));
			time.currentTime = time.gameClock.getElapsedTime().asSeconds();
			time.deltaTime = time.currentTime - time.lastTime;
			time.lastTime = time.currentTime;

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
				time.numEatenApples = 0;
				break;
			}

			MovePlayer(item, player, time);
			
			if (GameCollide(item, player, time, sound) == 0) {
				time.numEatenApples = 0;
				sound.Deth.play();
				break;
			}
			
			Fps(item, window, player, text, time);

		}

	}

	return 0;
}
