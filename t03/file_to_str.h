#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 2048

char *mx_strcpy(char *dst, const char *src);
char *mx_strcat(char* s1, const char* s2);
char *mx_strdup(const char *str);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_file_to_str(const char *filename);
bool mx_print_file(char *file_name);
