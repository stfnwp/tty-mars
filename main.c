#include <stdlib.h>
#include <ncurses.h>
#include <arraylist.h>
#include <json_pointer.h>
#include <json_util.h>
#include "print_matrix.h"
#include "parse_json.h"

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

	json_object *input_obj = json_object_from_file("input.json");
	json_object *sol_keys_obj;
	json_object_object_get_ex(input_obj, "sol_keys", &sol_keys_obj);
	array_list *sol_keys_array = json_object_get_array(sol_keys_obj);
	void *last_sol_keys_element = array_list_get_idx(sol_keys_array, array_list_length(sol_keys_array) - 1);
	int latest_sol = json_object_get_int((json_object *)last_sol_keys_element);

	json_object *temp_obj;
  json_pointer_getf(input_obj, &temp_obj, "/%d/HWS/av", latest_sol);
	double temperature = json_object_get_double(temp_obj);

	printf("sol: %d", latest_sol);
	printf("temp: %.2lf", temperature);
	//	char output_str[10];
	//	sprintf(output_str, "sol%s", sol);
	//	print_matrix(output_str);

	getch();
	endwin();
}