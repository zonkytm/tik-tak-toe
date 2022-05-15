#pragma once
#include "figure.h"
#include <iostream>
#include "Game_text.h"
#include "check_win.h"

void running_game() {

	RenderWindow window(VideoMode(512, 512), "tik tak toe");
	int player_1_win=0, player_2_win=0, draw=0;

	Turn turn;
	turn.set_position(Vector2f(512 / 2, 50));
	figure figures[3][3];

	Game_texts player_1_win_text(40, "", Vector2f(512/2-150, 400)),
		player_2_win_text(40, "", Vector2f(512 / 2, 400)),
		draw_text(40, "", Vector2f(512/2+150, 400));
	player_1_win_text.setFillColor(Color::Black);
	player_2_win_text.setFillColor(Color::Black);
	draw_text.setFillColor(Color::Black);
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			figures[i][j].set_position(Vector2f(135 + j * figures[i][j].get_sptite().getGlobalBounds().width, 135 + i * figures[i][j].get_sptite().getGlobalBounds().height));
		}
	}
	while (window.isOpen())
	{

		Event event;
		Vector2f mouse_position;
		mouse_position.x = Mouse::getPosition(window).x;
		mouse_position.y = Mouse::getPosition(window).y;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					if (turn.game_state <2)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{

								if (figures[i][j].get_sptite().getGlobalBounds().contains(mouse_position))
								{
									if (figures[i][j].state == figures[i][j].empty)
									{


										switch (turn.game_state)

										{
										case 0:
											figures[i][j].state = figures[i][j].cross;
											turn.game_state = turn.player2;
											break;
										case 1:
											turn.game_state = turn.player1;
											figures[i][j].state = figures[i][j].circle;
											break;
										default:
											break;
										}
									}
								}

							}
						}
					}
				
				}
			}
			if (turn.game_state >=2)
			{

				if (event.type == Event::KeyPressed)
				{
					if (event.key.code = Keyboard::Space)
					{
						switch (turn.game_state)

						{
						case 2:
							draw++;
							break;
						case 3:
							player_1_win++;
							break;
						case 4:
							player_2_win++;
							break;
						default:
							break;
						}
							for (int i = 0; i < 3; i++)
							{
								for (int j = 0; j < 3; j++)
								{
									figures[i][j].state = figures[i][j].empty;
									turn.game_state = turn.player1;
								}
							}

							

					}
				}
				

			}

		}




		turn.update();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				figures[i][j].update();

			}
		}

		check_win(turn, figures);

		player_1_win_text.set_string("player 1\n" + to_string(player_1_win));
		player_2_win_text.set_string("player 2\n" + to_string(player_2_win));
		draw_text.set_string("draw\n" + to_string(draw));
		
		window.clear(Color::White);
		window.draw(turn.get_sprite());

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				window.draw(figures[i][j].get_sptite());

			}
		}
		window.draw(player_1_win_text.get_game_text());
		window.draw(player_2_win_text.get_game_text());
		window.draw(draw_text.get_game_text());
		window.display();
	}


}

