#include "Player.h"
#include "Constants.h"
#include "Game.h"

namespace ApplesGame {
	void InitGamePlayer(Player& player,const Resurses& texture) {
		player.playerSprite.setTexture(texture.playerTexture);
		setSpriteSize(player.playerSprite, PLAYER_SIZE, PLAYER_SIZE);
		setSpriteRelativeOrigin(player.playerSprite, 0.5f, 0.5f);
	}
}