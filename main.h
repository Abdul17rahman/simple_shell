#ifndef header_file
#define header_file

#define BUF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int _strlen(char *s);

void _puts(char *str);

size_t word_count(char *s, char *del);

char *_strdup(char *str);

char **_split(char *str, char *del);

void _free_words(char **);

char *_read_line(void);
char *_get_path(char **env);
void _exit_command(char **arg, char *lineptr, int _exit);
void _getenv(char **env);
int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c);
void execmd(char **argv);
char *_strcat(char *dest, char *src);
void execute_cmd(char **args);
void *do_mem(size_t size, void *ptr);
static void do_exit(const char *msg, int code);
#endif
