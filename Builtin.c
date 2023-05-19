#include "shell.h"

/**
 * _myexit: an exit function for the shell program
 * @info: contains arguments which are likely to be parsed into the program
 * Return: gives the exit status, returns 0 if the array of info.arg[] is 
 * not equal to exit.
 */
int_myexit(info_t *info)
{
	int check_exit;

	/*checking for the existence of an exit argument*/
	if (info->arg[1])
	{
		/* the _erratoi function converts strings to integers*/
		check_exit = _erratoi(info->arg[1];
				check_exit = -1)
		{
			info->status = 2;
			print_error(info "number not allowed:");
			/*_eputs is a function which prints a string to std output*/
			_eputs(info->arg[1]);
			return (1);
			info->err_num = _erratoi(info->arg[1]);
			return (-2);
		}
		info->err_num = -1;
		return (-2);
	}
}
/**
 * _mycd - a function which changes the working directory 
 * @info: contains arguments which are likely to be parsed into the program
 * Return: the return value should always be  0
 */
int_mycd(info_t *info)
{
	char *s;

