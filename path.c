#include "shell.h"
#include <stdio.h>

/*
 * main - the main function
 * @argc: the number of count of variables
 * @argv: an array of pointers to argv
 * @env: envronment variables
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	int i;
	size_t z;

	char *PATH = _getenv("PATH");
	printf("%s/n", path);

	char **paths = split_string(path, ":", &i);
	for (z = 0; paths[z]; z++)
		printf("%d - %s\n", z, paths[z]);
	free_vector(paths, i);
	return (0);
}
