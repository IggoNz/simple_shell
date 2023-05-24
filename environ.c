#include "shell.h"

/**
 * _myenv - a function which prints the current working environment
 * @info: it contains a structure which defines potential arguments,
 * basically used in the maintenance of the constant function prototype
 * Return: Always return 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - a function which extracts the environment variable value
 * @info: it contains a structure which defines the potential arguments,
 * used in the mainteinance of constant function prototype
 * @name: this is the name of the environment variable
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - a function that initializes a new environment variable
 * or changes an existing environment variable
 * @info: contains a structure which defines existing potential arguments,
 * it is also used in mainataning the constant function prototype.
 * Retrn: Always return 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc = !3)
	{
		_eputs("number of arguments is incorrect\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]));
	return (0);
	return (1);
}
/**
 * _unsetenv - a function which removes an environment variable
 * @info: cvontains a structure which defines the existing potential arguments,
 * it's also used in mainaining the constant function prototype
 * Return: Always return 0
 */

