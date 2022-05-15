#include "figure.h"



void figure::place_figure(Turn turn) {

	if (state==empty)
	{
		if (turn.game_state==turn.player1)
		{
			state = cross;
		}
		else if (turn.game_state = turn.player2)
		{
			state = circle;
		}
	}
}


void figure::update() {

	switch (state)
	{
	case figure::empty:
		figure_sprite.setTextureRect(IntRect(0, 0, 16, 16));
		break;
	case figure::cross:
		figure_sprite.setTextureRect(IntRect(16, 0, 16, 16));
		break;
	case figure::circle:
		figure_sprite.setTextureRect(IntRect(32, 0, 16, 16));
		break;
	default:
		break;
	}

}

void figure::set_position(Vector2f position) {

	figure_sprite.setPosition(position);
}


Sprite figure::get_sptite() {
	return figure_sprite;
}