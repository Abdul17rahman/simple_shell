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

char *_strcat(char *dest, char *src);

void execute_cmd(char **args);

char *_get_path_loc(char *);

void _exit_command(char **arg, char *lineptr);

#endif
