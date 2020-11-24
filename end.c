#include "othello.h"

void	free_board(char **board, t_coordinate coor)
{
	int i;

	for (i = 0 ; i < coor.m ; i++)
		free(board[i]);
	free(board);
}

void	end_game(char **board, t_coordinate coor)
{
	int i;
	int j;
	int num_o;
	int num_x;

	num_o = 0;
	num_x = 0;

	i = 0;
	while (i < coor.m)
	{
		j = 0;
		while (j < coor.n)
		{
			if (board[i][j] == 'O')
				num_o++;
			if (board[i][j] == 'X')
				num_x++;
			j++;
		}
		i++;
	}

	printf("\nO : %d\nX : %d\n", num_o, num_x);
	if (num_o > num_x)
		printf("\n%c 승리!\n", 'O');
	else if (num_o < num_x)
		printf("\n%c 승리!\n", 'X');
	else
		printf("\n무승부\n");
	free_board(board, coor);
	exit(1);
}
