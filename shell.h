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
#define INFO_INIT\
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL,\
	0, 0, 0}
/**
 * struct builtin - contains a string which is builtin together with
 * a related function
 * @type: defines the builtin command flag
 * @func:defines the function of interest
 */
typedef struct builtin
{
	char *type;
	int(*func)(info_t*)
}builtin_table;
/*toem_vars.c*/
/*demonstrates the use of a while loop*/
int is_chain(info_t*, char*, size_t*);
int replace_alias(info t*);
int replace_string(char**, char*);
int replace_vars(info_t*);
void check_chain(info_t*, char*, size_t*);
/*toem_shloop.c*/
/*contains functions used in implementation of simple shell*/
void fork_cmd(info_t*);
void find_cmd(info_t*);
int hsh(info_t*, char**);
int find_builtin(info_t*);
/*loophsh.c*/
int loophsh(char **);
/*toem_lists.c*/
list_t *add_node(list_t**, const char*, int);
list_t *add_node_end(list_t**,const char*, int);
size_t print_list_str(const list_t*);
int delete_node_at_index(list_t**, unsigned int);
void free_list(list_t**);
/*toem_lists1.c*/
size_t print_list(const list_t*);
ssize_t get_node_index(list_t*, list_t*);
size_t list_len(const list_t*);
char **list_to_strings(list_t*);
list_t *node_starts_with(list_t*, char*, char);
/*toem_parser.c*/
int is_cmd(info_t*, char*);
char *dup_chars(char*, int, int);
char *find_path(info_t*, char*, char*);
/*toem_errors.c*/
int_putfd(char c, int fd);
int_putsfd(char *str, int fd);
int_eputchar(char);
void_eputs(char *);
/*toem_string.c*/
int_strlen(char *);
int_strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
/*toem_string1.c*/
int_putchar(char);
void_puts(char *);
char *_strcpy(char *, char *);
char *_strup(const char *);
/*toem_exits.c*/
char *_strncpy(char *, char *, int);
char *_strcat(char *, char *, int);
char *_strchr(char *, char);
/*toem_tokenizer.c*/
char **strtow(char *, char *);
char **strtow2(char *, char);
/*toem_realloc.c*/
char *_memset(char *,char, unsigned int);
void ffree(char **);
void *_realloc(void *,unsigned int, unsigned int);
/*toem_memory.c*/
int bfree(void**);
/*toem_atoi.c*/
int_isalpha(int);
int is_delim(char*, char);
int interactive(info_t*);
int_atoi (char*);
/*toem_builtin.c*/
int_myexit(info_t*);
int_mycd(info_t*);
int_myhelp(info_t*);
/*toem_errors1.c*/
int_erratoi(char*);
void print_error(info_t*, char*);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
/*toem_builtin1.c*/
int_myhistory(info_t*);
int_myalias((info_t*);
/*toem_getline.c*/
ssize_t_get_input(info_t*);
int_getline(info_t*, char **, size_t c*);
void sigitHandler(int);
/*toem_getinfo.c*/
void clear_info(info_t*);
void set_info(info_t*, char**);
void free_info(info_t*, int);
/*toem_environ.c*/
char*_getenv(info_t*, const char*);
int_myenv(info_t*);
int_mysetenv(info_t*);
int_myunsetenv(info_t*);
int populate_env_list(info_t*);
/*toem_getenv.c*/
char **get_environ(info_t*);
int_unsetenv(info_t*, char*);
int_setenv(info_t*, char*, char*);
/*toem_history.c*/
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

#endif
