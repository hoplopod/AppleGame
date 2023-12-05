#include "Items.h"
#include "Game.h"

namespace ApplesGame {
	void InitGameItems(Items& item, const Resurses& texture) {

		item.BlackCubeShape.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
		item.BlackCubeShape.setOrigin(PLAYER_SIZE / 2.f, PLAYER_SIZE / 2.f);
		item.BlackCubeShape.setFillColor(sf::Color::Black);
		item.BlackCubePosition.x = SCREEN_WIDTH / 2.f;
		item.BlackCubePosition.y = SCREEN_HEIGHT / 2.f;
		item.BlackCubeShape.setPosition(item.BlackCubePosition.x, item.BlackCubePosition.y);

		for (int i = 0; i < NUM_STONE; ++i) {
			item.stonePosition[i] = GetRandomPositionScreen(SCREEN_WIDTH, SCREEN_HEIGHT);

			item.stoneSprite[i].setTexture(texture.stoneTexture);
			setSpriteSize(item.stoneSprite[i], STONE_SIZE, STONE_SIZE);
			setSpriteRelativeOrigin(item.stoneSprite[i], 0.5f, 0.5f);
			item.stoneSprite[i].setPosition(item.stonePosition[i].x, item.stonePosition[i].y);
		}

		for (int i = 0; i < NUM_APPLES; ++i) {

			item.applesPosition[i] = GetRandomPositionScreen(SCREEN_WIDTH, SCREEN_HEIGHT);

			item.applesSprite[i].setTexture(texture.applesTexture);
			setSpriteSize(item.applesSprite[i], APPLES_SIZE, APPLES_SIZE);
			setSpriteRelativeOrigin(item.applesSprite[i], 0.5f, 0.5f);
			item.applesSprite[i].setPosition(item.applesPosition[i].x, item.applesPosition[i].y);

		}
	}
}