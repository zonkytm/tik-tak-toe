#pragma once

#include <SFML/Graphics.hpp>
#include "Turn.h"
using namespace sf;




class figure
{

	Texture figure_texture;
	Sprite figure_sprite;

public:
	enum {
		empty,
		cross,
		circle
	} state;

	figure()
	{
		figure_texture.loadFromFile("img/figure_sprites.png");
		figure_sprite.setTexture(figure_texture);
		figure_sprite.setTextureRect(IntRect(0, 0, 16, 16));
		
		figure_sprite.setScale(5, 5);
		state = empty;

	}

	void place_figure(Turn turn);
	void set_position(Vector2f position);
	void update();
	Sprite get_sptite();
};

