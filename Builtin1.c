#include "shell.h"

/**
 * _myhistory - displays the list of history, the commands are
 * written one by one  per line together with the line numbers starting with 0.
 * @info: it contains potential arguments which are parsed in the program.
 * These are used in the maintenance of the constant function prototype.
 * Return: always return 0.
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias -  sets the alias to a given string
 * @info: defines the structure of the parameters
 * @str: defines the alias of the string
 * Return: if successful return 0, if an error occurs return 1
 */
int set_alias(info_t *info, char *str)
{
	char *s, z;
	int ret;

	s = _strchr(str, '=');
	if (!s)
		return (1);
	z = *s;
	s = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*s = z;
	return (ret);
}
/**
 * set_alias - sets the alias to a given string
 * @info: defines the structure of the parameters.
 * @str: defines the alias of the string
 * Return: if successful return 0, if an error occurs return 1
 */
int set_alias(info_t, *info, char *str)
{
	char *s;

	s = _strchr(str, "=");
	if (!s)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return(add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - used in the printing of an alias of a string
 * @node: refers to the node of a string
 * Return: if successful return 0, if an error occurs return 1
 */
int print_alias(list_t *node)
{
	char *s = NULL, *z = NULL;

	if (node)
	{
		s = _strchr(node->str, "=");
		for (a = node->str; a<=p; a++)
			_putchar(*a);
		_putchar('\');
		_puts(s + 1);
		_puts("\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - this replicates the builtin alias by mimicking it
 * @info: it contains potential arguments which are parsed into the program
 * Return: always return 0.
 */
int _myalias(info_t *info)
{
	int y = 0;
	char *s = NULL;
	list_t *node = NULL;

	if (info->arg == 1)
	{
		node = info -> alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (y = 1; info->argv; y++)
	{
		s = _strchr(info->argv[y], '=');
		{
			if (s)
				set_alias(info, info->argv[y];
						else 
						print_alias(node_starts_with(info->alias, info->arg[y], '='));
		}
		return (0);
	}
}

