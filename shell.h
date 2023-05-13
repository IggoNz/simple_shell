#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.c>
#include <sys/wait.h>

/*used in reading and writing buffers*/
#define BUF_FLUSH - 1
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024

/*used in the process of doing command chaining*/
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/*used in the number conversion for convert_number()*/
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/*in the event the system getline() is used*/
#define USE_STRTOK 0
#define USE_GETLINE 0
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096
external char **environ;
/**
 * struct liststr - used to define a singly linked list
 * @num: identifies the exact number field
 * @str:refers to the string of interest
 * @next: it used to refer to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
	double dbl;
	struct liststr *prev;
}list_t;
/**
 * struct passinfo - has pseudo arguments which which are passed on a function
 * this allows the prototype to the function pointer to be uniform
 * @arg: refers to te string obtained from the getline which has arguments.
 * @argv: refers to an array consisting of strings,
 * this array is generated from arg
 * @path: refers to the path of a string for the current command
 * @argc: defines the number of arguments
 * @line_count: this is the error count
 * @err_num: defines the eror code used for exit()s
 * @linecount_flag: defines the line of input
 * @fname: defines the filename of the program
 * @env: defines a linked list containing a local copy of the environment
 * @environ: defines a copy of environ from LL env which
 * has been custom modified
 * @history: defines the history of the node
 * @alias: defines the alias of the node
 * @env_changed: shows whether the environment was changed
 * @status: shows the status of the last executed command
 * @cmd_buf: gives the address of the pointer to cmd_buf in case of if chaining
 * @cmd_buf_type: CMD_type || &&;
 * @readfd: defines the file descriptor from which the line input is read
 * @histcount: gives the history line numbr to be counted
 */
typedef struct passinfo
{
	/*the number of arguments*/
	int argc;
	/*a flag to indicate if the environment has been changed*/
	int env_changed;

	int err_num;
	int status;
	int linecount_flag;
	int readfd;
	int histcount;
	char *path;
	char **argv;
	char *arg;
	char **environ;
	char *filename;
	unsigned int line_count;
	list_t *alias;
	list_t *env;
	list_t *history;

	char **cmd_buf; /*it is a pointer to cmd and a chain buffer
			  to manage the memory*/
	int cmd_buf_type; /*CMD_type || && ;*/
}info_t;
