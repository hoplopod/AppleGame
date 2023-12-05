#pragma once

namespace sf {
	class Sprite;
}

namespace ApplesGame {

	struct Vector2D {
		float x = 0;
		float y = 0;
};

	typedef Vector2D Position2D;

	Position2D GetRandomPositionScreen(float screenWidth, float screenHeight);

	bool IsRectangleCollide(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size);

	bool isCircleCollide(Position2D rectPosition, float rectSize, Position2D CircleLPosition, float CircleRadius);

	void setSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);
	
	void setSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
}