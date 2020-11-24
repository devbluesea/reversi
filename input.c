#include "othello.h"

void	input_coordinate(t_coordinate *coor, int mode)
{
	while (1)
	{
		if (mode == 0)
		{
			printf ("N, M : ");
			scanf ("%d %d", &coor->n, &coor->m);
			if (coor->n < 0 && coor->m <0)
			{
				printf("양수를 입력해주세요.");
				continue;
			}
			if (coor->n <= 2 || coor->m <= 2 || coor->n % 2 == 1 || coor->m % 2 == 1)
			{
				printf("2보다 큰 짝수를 입력해주세요.\n");
				continue;
			}
			else
				break;
		}
		if (mode == 1)
		{
			printf ("x, y : ");
			scanf ("%d %d", &coor->x, &coor->y);
			if (coor->x < 0 && coor->y < 0)
			{
				printf("0이상의 수를 입력하세요.");
				continue;
			}
			if (coor->x < coor->n && coor->y < coor->m)
				break;
			else
			{
				printf("x = %d, y = %d 보다 작은 수를 입력하세요.\n", coor->n, coor->m);
				continue;
			}
		}
	}
}

void	set_board(char **board, t_coordinate coor)
{
	board[coor.m / 2][coor.n / 2] = 'O';
	board[coor.m / 2 - 1][coor.n / 2] = 'X';
	board[coor.m / 2][coor.n / 2 - 1] = 'X';
	board[coor.m / 2 - 1][coor.n / 2 - 1] = 'O';
}
