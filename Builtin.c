#include "shell.h"

/**
 * _myexit: an exit function for the shell program
 * @info: contains arguments which are likely to be parsed into the program
 * Return: gives the exit status, returns 0 if the array of info.arg[] is 
 * not equal to exit.
 */
int _myexit(info_t *info)
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
int _mycd(info_t *info)
{
	int chn_dir;
	char *z, *dir, buffer[1024];

	/* the getcwd is a function which gets the current working directory, takes 2 parameters*/
	z = getcwd(buffer, 1024);
	if (!z)
		_puts("TODO:>>generate the getcwd failure message<<\n");
	if (!info->argv[1])
	{
		/* _getenv is a function which gets environment variable, takes 2 paremeters*/
		dir = _getenv(info, "HOME=");
		if (!dir)
		{
			chn_dir = chdir((dir = _getenv(info, "PWD="))?DIR :"/";
					else
					chn_dir = chdir(dir);
		}
		/*_strcmp, compares 2 strings*/

		else if (_strcmp(info->arg[1], "-") == 0)
		{
		if(!_getenv(info, "OLDPWD="))
		{
		_puts(s);
		_putchar("\n");
		return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar("\n");
		chn_dir = chdir((dir =_getenv(info, "OLDPWD=")) ? dir : "/");
		}
		else 
		chn_dir = chdir(info->argv[1]);
		if (chn_dir == -1)
		{
			print_error(info,"cannot change directory to");
			_eputs(info->argv[1]), _eputchar("\n");
		}
		else
		{
			_setenv(info, "OLDPWD", _getenv(info, "PWD=");
					_setenv(info, "PWD", getcwd(buffer, 1024));
		}
		return (0);
	}
}
/**
 * _myhelp - a function that changes the current working directory of a shell program
 * @info: contyains arguments parsed into the program
 * Return: the return value is always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("the help call works, function implewmentation not yet done");
	if (0)
	_puts(*arg_array);
	return (0);
}
