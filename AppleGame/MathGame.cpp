#include "MathGame.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

namespace ApplesGame {
	Position2D GetRandomPositionScreen(float screenWidth, float screenHeight) {
		Position2D result;
		result.x = rand() / (float)RAND_MAX * screenWidth;
		result.y = rand() / (float)RAND_MAX * screenHeight;
		return result;
	}

	bool IsRectangleCollide(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size) {
		const float dx = fabs(rect1Position.x - rect2Position.x);
		const float dy = fabs(rect1Position.y - rect2Position.y);
		return (dx <= (rect1Size.x + rect2Size.x) / 2.f &&
			dy <= (rect1Size.y + rect2Size.y) / 2.f);
	}

	bool isCircleCollide(Position2D rectPosition, float rectSize, Position2D CircleLPosition, float CircleRadius) {
		const float squareDistance = (rectPosition.x - CircleLPosition.x) * (rectPosition.x - CircleLPosition.x) +
			(rectPosition.y - CircleLPosition.y) * (rectPosition.y - CircleLPosition.y);
		const float squareRadiusSum = (CircleRadius + rectSize) * (CircleRadius + rectSize);
		return squareDistance <= squareRadiusSum;
	}

	void setSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight) {
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = { desiredWidth / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}
	void setSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY){
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}
}