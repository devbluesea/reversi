#include "othello.h"

int		right_check(char **board, t_coordinate *coor, int tic_tok, int mode)
{
	int i;
	int j;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';
	if (coor->x == coor->n - 1 || coor->x == coor->n - 2)
		return (0);
	if (board[coor->y][coor->x + 1] == stone)
		return (0);
	i = coor->x + 1;
	while (i < coor->n)
	{
		if (board[coor->y][i] == '.')
			return (0);
		if (board[coor->y][i] == stone)
		{
			j = coor->x + 1;
			while (j < i && mode == 1)
			{
				board[coor->y][j] = tic_tok == 0 ? 'O' : 'X';
				j++;
			}
			return(1);
		}
		i++;
	}
	return (0);
}

int		right_upper_check(char **board, t_coordinate *coor, int tic_tok, int mode)
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';
	if (coor->x == coor->n - 1 || coor->x == coor->n - 2 || coor->y == 0 || coor->y == 1)
		return (0);
	if (board[coor->y - 1][coor->x + 1] == stone)
		return (0);
	i = coor->x + 1;
	j = coor->y - 1;

	while (i < coor->n && j >= 0)
	{
		if (board[j][i] == '.')
			return (0);
		if (board[j][i] == stone)
		{
			k = coor->x + 1;
			l = coor->y - 1;
			while (k < i && l > j && mode == 1)
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';
				k++;
				l--;
			}
			return(1);
		}
		i++;
		j--;
	}
	return (0);
}

int		right_lower_check(char **board, t_coordinate *coor, int tic_tok, int mode)
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';
	if (coor->x == coor->n - 1 || coor->x == coor->n - 2 || coor->y == coor->m - 1 || coor->y == coor->m - 2)
		return (0);
	if (board[coor->y + 1][coor->x + 1] == stone)
		return (0);
	i = coor->x + 1;
	j = coor->y + 1;
	while (i < coor->n && j < coor->m)
	{
		if (board[j][i] == '.')
			return (0);
		if (board[j][i] == stone)
		{
			k = coor->x + 1;
			l = coor->y + 1;
			while (k < i && l < j && mode == 1)
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';
				k++;
				l++;
			}
			return(1);
		}
		i++;
		j++;
	}
	return (0);
}

int		lower_check(char **board, t_coordinate *coor, int tic_tok, int mode)
{
	int i;
	int j;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';
	if (coor->y == coor->m - 1 || coor->y == coor->m - 2)
		return (0);
	if (board[coor->y + 1][coor->x] == stone)
		return (0);
	i = coor->y + 1;
	while (i < coor->m)
	{
		if (board[i][coor->x] == '.')
			return (0);
		if (board[i][coor->x] == stone)
		{
			j = coor->y + 1;
			while (j < i && mode == 1)
			{
				board[j][coor->x] = tic_tok == 0 ? 'O' : 'X';
				j++;
			}
			return(1);
		}
		i++;
	}
	return (0);
}

int		upper_check(char **board, t_coordinate *coor, int tic_tok, int mode)
{
	int i;
	int j;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';
	if (coor->y == 0 || coor->y == 1)
		return (0);
	if (board[coor->y - 1][coor->x] == stone)
		return (0);
	i = coor->y - 1;
	while (i >= 0)
	{
		if (board[i][coor->x] == '.')
			return (0);
		if (board[i][coor->x] == stone)
		{
			j = coor->y - 1;
			while (j > i && mode == 1)
			{
				board[j][coor->x] = tic_tok == 0 ? 'O' : 'X';
				j--;
			}
			return(1);
		}
		i--;
	}
	return (0);
}

int		left_check(char **board, t_coordinate *coor, int tic_tok, int mode)
{
	int i;
	int j;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';
	if (coor->x == 0 || coor->x == 1)
		return (0);
	if (board[coor->y][coor->x - 1] == stone)
		return (0);
	i = coor->x - 1;
	while (i >= 0)
	{
		if (board[coor->y][i] == '.')
			return (0);
		if (board[coor->y][i] == stone)
		{
			j = coor->x - 1;
			while (j > i && mode == 1)
			{
				board[coor->y][j] = tic_tok == 0 ? 'O' : 'X';
				j--;
			}
			return(1);
		}
		i--;
	}
	return (0);
}

int		left_upper_check(char **board, t_coordinate *coor, int tic_tok, int mode)
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';
	if (coor->x == 0 || coor->x == 1 || coor->y == 0 || coor->y == 1)
		return (0);
	if (board[coor->y - 1][coor->x - 1] == stone)
		return (0);
	i = coor->x - 1;
	j = coor->y - 1;
	while (i >= 0 && j >= 0)
	{
		if (board[j][i] == '.')
			return (0);
		if (board[j][i] == stone)
		{
			k = coor->x - 1;
			l = coor->y - 1;
			while (k > i && l > j && mode == 1)
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';
				k--;
				l--;
			}
			return(1);
		}
		i--;
		j--;
	}
	return (0);
}

int		left_lower_check(char **board, t_coordinate *coor, int tic_tok, int mode)
{
	int i;
	int j;
	int k;
	int l;
	char stone;

	stone = tic_tok == 0 ? 'O' : 'X';
	if (coor->x == 0 || coor->x == 1 || coor->y == coor->m - 1 || coor->y == coor->m - 2)
		return (0);
	if (board[coor->y + 1][coor->x - 1] == stone)
		return (0);
	i = coor->x - 1;
	j = coor->y + 1;
	while (i >= 0 && j < coor->m)
	{
		if (board[j][i] == '.')
			return (0);
		if (board[j][i] == stone)
		{
			k = coor->x - 1;
			l = coor->y + 1;
			while (k > i && l < j && mode == 1)
			{
				board[l][k] = tic_tok == 0 ? 'O' : 'X';
				k--;
				l++;
			}
			return(1);
		}
		i--;
		j++;
	}
	return (0);
}

int		eight_check(char **board, t_coordinate *coor, int tic_tok, int mode)
{
	int eight_flag[8];
	int i;

	i = 0;
	eight_flag[0] = right_check(board, coor, tic_tok, mode);
	eight_flag[1] = right_upper_check(board, coor, tic_tok, mode);
	eight_flag[2] = right_lower_check(board, coor, tic_tok, mode);
	eight_flag[3] = lower_check(board, coor, tic_tok, mode);
	eight_flag[4] = upper_check(board, coor, tic_tok, mode);
	eight_flag[5] = left_check(board, coor, tic_tok, mode);
	eight_flag[6] = left_upper_check(board, coor, tic_tok, mode);
	eight_flag[7] = left_lower_check(board, coor, tic_tok, mode);

	while (i < 8)
	{
		if (eight_flag[i] == 1)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
