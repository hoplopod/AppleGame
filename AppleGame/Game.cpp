#include <cassert>
#include <iostream>

#include "Game.h"
#include "Player.h"

namespace ApplesGame {

	void PlayerSpawnEffect(Time& time, Player& player, sf::RenderWindow& window, Items& item, Resurses& text)
	{
		time.gameClock.restart();
		time.lastTime = time.gameClock.getElapsedTime().asSeconds();
		
		while (time.lastTime < 2.5f)
		{
			time.lastTime = time.gameClock.getElapsedTime().asSeconds();
			Fps(item, window, player, text, time);
			sf::sleep(sf::milliseconds(300));
			Fps(item, window, player, text, time);
			window.draw(item.BlackCubeShape);
			window.display();
			sf::sleep(sf::milliseconds(300));
		}
		time.gameClock.restart();
		time.lastTime = time.gameClock.getElapsedTime().asSeconds();
		
	}

	void Textures(Resurses& texture, Resurses& sound, Resurses& text) {
		assert(texture.playerTexture.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(texture.stoneTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));
		assert(texture.applesTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));

		assert(sound.PlayerDie.loadFromFile(RESOURCES_PATH + "\\Death.wav"));
		sound.Deth.setBuffer(sound.PlayerDie);
		sound.Deth.setVolume(50.f);
		assert(sound.EatApple.loadFromFile(RESOURCES_PATH + "\\AppleEat.wav"));
		sound.Eat.setBuffer(sound.EatApple);
		sound.Eat.setVolume(50.f);

		assert(text.Arcada.loadFromFile(RESOURCES_PATH + "\\fontArcada.ttf"));
		text.Score.setFont(text.Arcada);
		text.Score.setCharacterSize(24);
		text.Score.setStyle(sf::Text::Regular);
		text.Score.setFillColor(sf::Color::White);
		text.Score.setPosition(10.f, 10.f);
	}

	int GameCollide(Items& item, Player& player, Time& time, Resurses& sound) {
		if (player.playerPosition.x - PLAYER_SIZE / 2.f < 0.f || player.playerPosition.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH ||
			player.playerPosition.y - PLAYER_SIZE / 2.f < 0.f || player.playerPosition.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT) {
			return 0;
		}

		for (int i = 0; i < NUM_STONE; ++i) {
			if (item.stonePosition[i].x < SCREEN_WIDTH / 2.f + 50 && item.stonePosition[i].x > SCREEN_WIDTH / 2.f - 50 &&
				item.stonePosition[i].y < SCREEN_HEIGHT / 2.f + 50 && item.stonePosition[i].y > SCREEN_HEIGHT / 2.f - 50 ) {
				item.stonePosition[i] = GetRandomPositionScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
		}

		for (int i = 0; i < NUM_STONE; ++i) {
			if (IsRectangleCollide(player.playerPosition, { PLAYER_SIZE, PLAYER_SIZE }, item.stonePosition[i], { STONE_SIZE, STONE_SIZE })) {
				return 0;
			}
		}

		for (int i = 0; i < NUM_APPLES; ++i) {
			if (isCircleCollide(player.playerPosition, PLAYER_SIZE / 2.f, item.applesPosition[i], APPLES_SIZE / 2.f)) {
				++time.numEatenApples;
				if (time.numEatenApples > time.bestScore) {
					time.bestScore = time.numEatenApples;
				}
				item.applesPosition[i] = GetRandomPositionScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
				item.applesSprite[i].setPosition(item.applesPosition[i].x, item.applesPosition[i].y);

				player.playerSpeed += PLAYER_SPEED_PLUS;

				sound.Eat.play();
			}
		}

		for (int i = 0; i < NUM_APPLES; ++i) {
			for (int j = 0; j < NUM_STONE; ++j) {
				if (isCircleCollide(item.stonePosition[j], STONE_SIZE / 2.f, item.applesPosition[i], APPLES_SIZE / 2.f)) {
					item.applesPosition[i] = GetRandomPositionScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
					item.applesSprite[i].setPosition(item.applesPosition[i].x, item.applesPosition[i].y);
				}
			}
		}

		return 1;
	}

	void MovePlayer(Items& item, Player& player, Time& time) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			player.playerDirection = PlayerDirection::Pause;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			setSpriteSize(player.playerSprite, PLAYER_SIZE, PLAYER_SIZE);
			player.playerSprite.setRotation(0.f);
			player.playerDirection = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			setSpriteSize(player.playerSprite, PLAYER_SIZE, PLAYER_SIZE);
			player.playerSprite.setRotation(270.f);
			player.playerDirection = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			setSpriteSize(player.playerSprite, PLAYER_SIZE, -1*PLAYER_SIZE);
			player.playerSprite.setRotation(180.f);
			player.playerDirection = PlayerDirection::left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			setSpriteSize(player.playerSprite, PLAYER_SIZE, -1*PLAYER_SIZE);
			player.playerSprite.setRotation(90.f);
			player.playerDirection = PlayerDirection::Down;
		}

		switch (player.playerDirection)
		{
		case PlayerDirection::Right: {
			player.playerPosition.x += player.playerSpeed * time.deltaTime;
			break;
		}
		case PlayerDirection::Up: {
			player.playerPosition.y -= player.playerSpeed * time.deltaTime;
			break;
		}
		case PlayerDirection::left: {
			player.playerPosition.x -= player.playerSpeed * time.deltaTime;
			break;
		}
		case PlayerDirection::Down: {
			player.playerPosition.y += player.playerSpeed * time.deltaTime;
			break;
		}
		}
	}

	void Fps(Items& item, sf::RenderWindow& window, Player& player, Resurses& text, Time& time) {
		window.clear();
		player.playerSprite.setPosition(player.playerPosition.x, player.playerPosition.y);
		for (int i = 0; i < NUM_APPLES; ++i) {
			window.draw(item.applesSprite[i]);
		}
		for (int i = 0; i < NUM_STONE; ++i) {
			window.draw(item.stoneSprite[i]);
		}
		window.draw(player.playerSprite);

		text.Score.setString("Best result: " + std::to_string(time.bestScore) + " Score: " + std::to_string(time.numEatenApples));

		window.draw(text.Score);

		window.display();
	}

	void DeinializeGame(Items& item, Player& player) {
		setSpriteSize(player.playerSprite, PLAYER_SIZE, PLAYER_SIZE);
		player.playerSprite.setRotation(0.f);
		player.playerPosition.x = SCREEN_WIDTH / 2.f;
		player.playerPosition.y = SCREEN_HEIGHT / 2.f;
		player.playerDirection = PlayerDirection::Right;
		player.playerSpeed = INITIAL_SPEED;
	}

}