#include "shell.h"

/**
 * _eputs - prints a string to output
 * @str: the string of interest which is to be printed
 * Return: no return value
 */
void _eputs(char *str)
{
	int i;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
/**
 * _eputchar - a function which writes the c character to std error
 * @c: the character of interest which is to be printed
 * Return: if successful return 1, if an error occurs return -1
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putfd - writes the c character to a given file descriptor
 * @c: the c character of interest which is to be printed
 * @fd: the file descriptor which will be written to
 * Return: if successful return 1, if an error occurs return -1
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf(WRITE_BUF_SIZE);

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write (fd, i, buf);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buff[i++] = c;
	return (1);
}
/**
 * _putsfd - prints a given string parameter to file descriptor
 * @str: the string of interest which is to be printed
 * @fd: the file descriptor which the string will be printed to
 * Return: the number of characters to be printed
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
