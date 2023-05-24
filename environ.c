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
 * @info: contains a structure which defines the existing potential arguments,
 * it's also used in mainaining the constant function prototype
 * Return: Always return 0
 */
int _myunsetenv(info_t *info)
{
	int i;
	if (info->argc == 1)
	{
		_eputs("too minimal arguments\n");
		return (1);
	}
	for (i = 1; i<=info->argc; i++)
		_myusetenv(info, info->[i]);
	return (0);
}

/**
 * populate_env_list - populates a list which has ben linked environmentally
 * @info: contains a structure which defines the existing potential arguments,
 * Return: Always return 0
 */
int populate_env_list(info_t *info)
{
	list_t 8node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
