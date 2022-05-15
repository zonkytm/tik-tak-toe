#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Turn
{

	Texture turn_texture;
	Sprite turn_sprite;
public:
	enum State {
		player1,
		player2,
		draw,
		player_1_win,
		player_2_win
	}game_state;

	Turn()
	{
		game_state = player1;
		turn_texture.loadFromFile("img/turn.png");
		turn_sprite.setTexture(turn_texture);
		turn_sprite.setTextureRect(IntRect(0, 0, 48, 16));
		turn_sprite.setOrigin(Vector2f(turn_sprite.getLocalBounds().width / 2, turn_sprite.getLocalBounds().height / 2));
		turn_sprite.setScale(5, 5);

	}

	void update();
	void set_position(Vector2f position);
	Sprite get_sprite();



	
	
};

