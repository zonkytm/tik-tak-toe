#include "Turn.h"



void Turn::update() {

	switch (game_state)
	{
	case Turn::player1:
		turn_sprite.setTextureRect(IntRect(0, 0, 48, 16));
		break;
	case Turn::player2:
		turn_sprite.setTextureRect(IntRect(48, 0, 48, 16));
		break;
	case Turn::end:
		turn_sprite.setTextureRect(IntRect(48*2-1, 0, 48, 16));
		break;
	default:
		break;
	}
}


void Turn::set_position(Vector2f position) {

	turn_sprite.setPosition(position);
}

Sprite Turn::get_sprite() {
	return turn_sprite;
}