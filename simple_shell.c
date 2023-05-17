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
	/* replacing the newline char with null terminator */
	if (buff[bytes - 1] == '\n')
		buff[bytes - 1] = '\0';
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
int _execute(char *arg, struct stat *statbuf, char **envp)
{
	int argc;
	char **argv;
	char *exe;

	argv = split_string(arguments, " ", &argc);

	/* checking for an executable file */
	if (!check_file_status(argv[0], statbuf))
	{
		perror("Error (file status)");
		exit(EXIT_FAILURE);
	}
	execve(argv[0], argv, envp);
	/* to free the argv array which is dynamically allocated */
	/* in the event execve fails */
	perror("Error (execve)");
	exit(EXIT_FAILURE);
}

bool check_file_status(char *pathname, struct stat *statbuf)
{
	int stat_return;

	stat_return = stat(pathname, statbuf);
	if (stat_return == 0)
		return (1);
	return (0);
}
void handle_error(pid_t pid)


