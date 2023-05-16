#include <shell.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * main - this is a simple shell program that executes various shell
 * commands and displays a prompt
 * @argc: this is a count of the number of arguments which will be passed
 * to the main program
 * @argv: an array of character pointers pointing to a null terminated string
 * having an argument from the stated command line.
 * @env: array of character pointers pointing to an environment variable
 * contained in a null terminated string.
 */
int main(int argc, char *argv[], char **env)
{
	struct stat statbuf;
	int wstatus;
	bool from_pipe = false;
	ssize_t bytes;
	size_t buff size = 0;
	char *buff = NULL, *prompt = "$ ";
	pid_t wpid;

	while (true & !from_pipe)
	{
		/*evaluate if data is piped into the program*/
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = 1;
	/* output and print the prompts ($) in the given terminal */
	write(STDOUT_FILENO, prompt, 2);
	/* read the std input data */
	bytes = getline(&buff, &buff_size, stdin);
	if (bytes == -1)
	{
		perror("Error (getline)");
		free(buff); /*free the memory if the getline is not successful*/
		exit(EXIT_FAILURE);
	}

