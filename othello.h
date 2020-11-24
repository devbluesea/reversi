#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct	s_coordinate
{
	unsigned int n;
	unsigned int m;
	unsigned int x;
	unsigned int y;
}				t_coordinate;

void	input_coordinate(t_coordinate *coor, int mode);
void	set_board(char **board, t_coordinate coor);

int		right_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		right_upper_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		right_lower_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		lower_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		upper_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		left_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		left_upper_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		left_lower_check(char **board, t_coordinate *coor, int tic_tok, int mode);
int		eight_check(char **board, t_coordinate *coor, int tic_tok, int mode);

int		turn_check(char **board, t_coordinate *coor, int tic_tok);
int		blank_OX_check(char **board, t_coordinate *coor);

void	print_board(char **board, t_coordinate coor);

void	free_board(char **board, t_coordinate coor);
void	end_game(char **board, t_coordinate coor);
