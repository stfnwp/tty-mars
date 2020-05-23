#include <stdio.h>
#include <string.h>
#include "parse_json.h"

json_object *parse_json(char *json_str)
{
	json_tokener *tok = json_tokener_new();
	json_object *jobj = NULL;
	int stringlen = 0;
	enum json_tokener_error jerr;
	do
	{
		stringlen = strlen(json_str);
		jobj = json_tokener_parse_ex(tok, json_str, stringlen);
	} while ((jerr = json_tokener_get_error(tok)) == json_tokener_continue);
	if (jerr != json_tokener_success)
	{
		fprintf(stderr, "Error: %s\n", json_tokener_error_desc(jerr));
	}
	return jobj;
}