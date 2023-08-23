#include "main.h"

/**
 * get_specifier - finds the format function
 * @s: the format
 * Return: the number of bytes printed
*/

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
	{"c", print_char},
	{"d", print_int},
	{"i", print_int},
	{"s", print_string},
	{"%", print_percent},
	{"b", print_binary},
	{"o", print_octal},
	{"u", print_unsigned},
	{"x", print_hex},
	{"X", print_HEX},
	{"p", print_address},
	{"S", print_S},
	{"r", print_rev},
	{"R", print_rot13},
	{NULL, NULL}
	};
	int i = 0;

	while (specifier[i].specifier[0])
	{
		if (*s == specifier[i].specifier[0])
		{
		return (specifier[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_flag - finds the flag fun
 * @s: the format string
 * @params: parameters strut
 * Return: if flag was valid
*/

int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifer - finds the modifier func
 * @s: the formt string
 * @params: the parameters struct
 * Return: if modifier was valid
*/

int get_modifier(char *s, params_t *params)
{
	int i = 0

	switch (*s)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l.modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
*/

char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
