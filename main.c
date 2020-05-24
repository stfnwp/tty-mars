#include <stdlib.h>
#include <ncurses.h>
#include "get_weather.h"
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

	struct WeatherData wd = get_weather();

	char output_str[20];
	sprintf(output_str, "%d %.0lfDf", wd.sol, wd.temperature);
	print_matrix("sol temp");
	print_matrix(output_str);
	
	getch();
	endwin();
}