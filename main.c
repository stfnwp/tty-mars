#include <glib.h>
#include <ncurses.h>
#include "get_weather.h"
#include "print_matrix.h"

int main(int argc, char *argv[])
{
	initscr();
	use_default_colors();
	curs_set(false);
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);

	struct WeatherData wd = get_weather();

	GString *output_str = g_string_new("");
	g_string_printf(output_str, "%d %.0lfDf", wd.sol, wd.temperature);

	print_matrix("sol temp");
	print_matrix(output_str->str);

	g_string_free(output_str, TRUE);

	getch();
	endwin();
}
