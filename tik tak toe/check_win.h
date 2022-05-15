#pragma once
#include "figure.h"
#include "Turn.h"


bool is_same_number(figure  figures[3]) {
	int bufer = -1;
	if (figures[0].state != figures[0].empty)
	{
		bufer = figures[0].state;
	}


	for (int i = 0; i < 3; i++)
	{
		
		if (figures[i].state != bufer) {

			return 0;
		}



	}
	

	return 1;
}

void transponirovanie(figure figures[3][3], Turn& turn) {
	figure transpon_figures[3][3];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
		
			transpon_figures[i][j].state = figures[j][i].state;
			
		}

	}
	for (int i = 0; i < 3; i++)
	{
		if (is_same_number(transpon_figures[i]))
		{

			turn.game_state = turn.end;
			break;
		}
	}
}

void diagonal(figure figures[3][3], Turn& turn) {
	figure first_diagonal[3], second_diagonal[3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i==j)
			{
				first_diagonal[i].state = figures[i][j].state;
			}
			if (abs(i-j)==2 or (j==i and i==1))
			{
				second_diagonal[i].state = figures[i][j].state;
			}
		}
	}
	if (is_same_number(first_diagonal) or is_same_number(second_diagonal))
	{
		turn.game_state = turn.end;
	}
}

void check_win(Turn& turn, figure figures[3][3]) {
	
	
	
	transponirovanie(figures, turn);
	diagonal(figures, turn);
	int count_not_empty_cell = 0;
	for (int  i = 0; i < 3; i++)
	{

		if (is_same_number(figures[i]))
		{
			
			turn.game_state = turn.end;
			break;
		}

		for (int j = 0; j < 3; j++)
		{
			if (figures[i][j].state!=figures[i][j].empty)
			{
				count_not_empty_cell++;
			}
		}

	}
	if (count_not_empty_cell==9)
	{
		turn.game_state = turn.end;
	}
	
}