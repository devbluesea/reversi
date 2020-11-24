#include "othello.h"

int main(void)
{
	int i;
	int j;
	t_coordinate coor;
	int tic_tok;
	char **board;
	int temp;

	input_coordinate(&coor, 0);
	board = malloc(sizeof(char *) * (coor.m));

	for (i = 0 ; i < coor.m ; i++)
	{
		board[i] = malloc(sizeof(char) * (coor.n));
		for (j = 0 ; j < coor.n ; j++)
		{
			board[i][j] = '.';
		}
	}

	set_board(board, coor);
	print_board(board, coor);

	tic_tok = 0;

	while (1)
	{
		if (turn_check(board, &coor, tic_tok) == FALSE)
			tic_tok = tic_tok == 0 ? 1 : 0;
		blank_OX_check(board, &coor);
		printf("turn : %c\n", tic_tok == 0 ? 'O' : 'X');
		while (1)
		{
			input_coordinate(&coor, 1);
			if (board[coor.y][coor.x] == '.' && eight_check(board, &coor, tic_tok, 1) == TRUE)
			{
				board[coor.y][coor.x] = tic_tok == 0 ? 'O' : 'X';
				tic_tok = tic_tok == 0 ? 1 : 0;
				break;
			}
			else
				printf("여기에는 둘 수 없습니다.\n");
		}
		print_board(board, coor);
	}
	end_game(board, coor);
	free_board(board, coor);
	return (0);
}
