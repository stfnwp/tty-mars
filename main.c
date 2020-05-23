#include <stdlib.h>
#include <ncurses.h>
#include "print_matrix.h"

int main(int argc, char *argv[])
{
	initscr();
	curs_set(false);
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_GREEN);

	print_matrix("sol533");

	getch();
	endwin();
}