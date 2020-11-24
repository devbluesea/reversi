#include "othello.h"

int		turn_check(char **board, t_coordinate *coor, int tic_tok)
{
	int i;
	int j;
	int x_max;
	int y_max;

	x_max = coor->n;
	y_max = coor->m;

	for (i = 0 ; i < y_max ; i++)
	{
		coor->y = i;
		for (j = 0 ; j < x_max ; j++)
		{
			coor->x = j;
			if (eight_check(board, coor, tic_tok, 0) == TRUE)
			{
				return (TRUE);
			}
		}
	}
	tic_tok = tic_tok == 0 ? 1 : 0;
	for (i = 0 ; i < y_max ; i++)
	{
		coor->y = i;
		for (j = 0 ; j < x_max ; j++)
		{
			coor->x = j;
			if (eight_check(board, coor, tic_tok, 0) == TRUE)
			{
				tic_tok = tic_tok == 0 ? 1 : 0;
				printf("턴이 넘어갑니다.\n");
				return (FALSE);
			}
		}
	}
	printf("\n게임 끝!\n");
	end_game(board, *coor);
	return (2);
}

int		blank_OX_check(char **board, t_coordinate *coor)
{
	int i;
	int j;
	int x_max;
	int y_max;
	int blank_flag;
	int o_flag;
	int x_flag;

	x_max = coor->n;
	y_max = coor->m;

	blank_flag = 0;
	o_flag = 0;
	x_flag = 0;
	for (i = 0 ; i < y_max ; i++)
	{
		coor->y = i;
		for (j = 0 ; j < x_max ; j++)
		{
			coor->x = j;
			if (board[i][j] == '.')
				blank_flag = 1;
			if (board[i][j] == 'O')
				o_flag = 1;
			if (board[i][j] == 'X')
				x_flag = 1;
		}
	}
	if (blank_flag == 1 && o_flag == 1 && x_flag == 1)
		return (TRUE);
	else
		end_game(board, *coor);
	return (FALSE);
}
