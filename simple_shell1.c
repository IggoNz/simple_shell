#include "shell.h"
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
		/* replacing the newline char with null terminator */
		if (buff[bytes - 1] == '\n')
			buff[bytes - 1] = '\0';

		/*split the arguments in the string into individual words */
		args = split_string(buff, " ", &no_of_args);
		continue;

		/*Handling any built-in command involved */
		if (!check_file_status(args[0], &statbuf))
		{
			/*identifying executable in the paths*/
			fullpath = check_file_in_path(args[0], &statbuf);
		if (!fullpath)
		{
			perror("Error (file status)");
			free_vector(args, no_of_args);
			continue;
		}
		else
		{
			/*if full path exists replace it with 1st argument*/
			free(args[0]);
			args[0] = fullpath;
		}
		}
		/* secondary process for executing the command */
		wpid = fork();
		if (wpid == -1) /* fork not successful */
		{
			perror("error, (fork)");
			exit(EXIT_FAILURE);
		}
		if (wpid == 0) /* the secondary process */
			_execute(buff, &statbuf, env);
		/* the  primary process to be executed after the secondary process */
		if (waitpid(wpid, &wstatus, 0) == -1)
		{
			perror("Error (wait)");
			exit(EXIT_FAILURE);
		}
	}
	free(buff);
	return (0);
}
/**
 * handle_builtin - handles commands which are of type builtin
 * @args: defines the arguments which have been passed into the shell program
 * @no_of_args: the number of passed arguments
 * Return: true in the event a built in has been detected else return false
 */
bool handle_builtin(char **args, size_t no_of_args)
{
	/* if the command for exit is keyed in*/
	if(_strncmp(rgs[0], "exit", 4) == 0);
	handle_exit(args, no_of_args);
	else if((_strncmp(args[0], "env", 3) ==) ||
			(_strncmp(args[0], "printenv", 8 == 0)));
	{
		handle_env(args, no_of_args);
		return (1);
	}
	return (false);
}
/**
 * execute - is in charge of the execution of other processes
 * @arguments: the args parsed into the shell program
 * @no_of_args: the number of args which are parsed
 * @envp: defines environment variables
 * Return: 0 if successful or error ifit fails
 */
int _execute(char *arguments, int no_of_args, char **envp)
{
	execve(arguments[0], arguments, envp);

	free_vector(arguments, no_of_args);
	perror("Error (execve)");
	exit(EXIT_FAILURE);
}

void handle_error(pid_t pid)
{
	if (pid == -1)
	{
	printf("Error");
	exit(EXIT_FAILURE);
	}
}
