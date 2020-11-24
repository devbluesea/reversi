#include "othello.h"

void	print_board(char **board, t_coordinate coor)
{
	int i;
	int j;

	printf(" \e[1;1H\e[2J");
	printf("\n ");
	for (i = 0 ; i < coor.n ; i++)
		printf("% d", i);
	printf("\n");
	for (i = 0 ; i < coor.m ; i++)
	{
		printf("%d ", i);
		for (j = 0 ; j < coor.n ; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
