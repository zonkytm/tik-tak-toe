#pragma once

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Game_texts {
	Font font;
	Text game_text;
public:
	Game_texts(int font_size, string text, Vector2f position) {
		font.loadFromFile("font/game_text.ttf");
		game_text.setString(text);
		game_text.setCharacterSize(font_size);
		game_text.setFont(font);
		game_text.setOrigin(game_text.getGlobalBounds().width / 2, game_text.getGlobalBounds().height / 2);
		game_text.setPosition(position);
	}

	void setFillColor(Color color) {
		game_text.setFillColor(color);
	}

	void set_string(string text) {
		game_text.setString(text);
	}
	Text get_game_text() {
		return game_text;
	}

};