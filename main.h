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

int _strlen(char *s);

void _puts(char *str);

size_t word_count(char *s, char *del);

char *_strdup(char *str);

char **_split(char *str, char *del);

void _free_words(char **);

char *_read_line(void);

#endif
