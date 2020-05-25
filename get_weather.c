#include <glib.h>
#include <arraylist.h>
#include <json_pointer.h>
#include <json_tokener.h>
#include <json_util.h>
#include "get.h"
#include "get_weather.h"

json_object *parse_json(char *json_str)
{
	json_tokener *tok = json_tokener_new();
	json_object *jobj = NULL;
	enum json_tokener_error jerr;
	do
	{
		jobj = json_tokener_parse_ex(tok, json_str, strlen(json_str));
	} while ((jerr = json_tokener_get_error(tok)) == json_tokener_continue);
	if (jerr != json_tokener_success)
	{
		g_printerr("Error: %s\n", json_tokener_error_desc(jerr));
	}
	return jobj;
}

struct WeatherData get_weather()
{
	struct WeatherData wd;

	char *api_key = getenv("API_KEY") != NULL ? getenv("API_KEY") : "DEMO_KEY";
	GString *url = g_string_new("");
	g_string_printf(url, "https://api.nasa.gov/insight_weather/?api_key=%s&feedtype=json&ver=1.0", api_key);
	char *response = get(url->str);

	//json_object *input_obj = json_object_from_file("input.json");
	json_object *input_obj = parse_json(response);
	json_object *sol_keys_obj;
	json_object_object_get_ex(input_obj, "sol_keys", &sol_keys_obj);
	array_list *sol_keys_array = json_object_get_array(sol_keys_obj);
	void *last_sol_keys_element = array_list_get_idx(sol_keys_array, array_list_length(sol_keys_array) - 1);
	wd.sol = json_object_get_int((json_object *)last_sol_keys_element);

	json_object *temp_obj;
	json_pointer_getf(input_obj, &temp_obj, "/%d/HWS/av", wd.sol);
	wd.temperature = json_object_get_double(temp_obj);

	return wd;
}