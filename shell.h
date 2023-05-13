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
 * @argv: refers to an array consisting of strings, this array is generated from arg
 * @path: refers to the path 
