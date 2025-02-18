#pragma once

#include <stdbool.h>
#include <stdlib.h>

void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
char **mx_strsplit(char const *s, char c);
char *mx_skip_spaces(char *str);
char *mx_strnew(const int size);
int mx_count_words(const char *str, char delimiter);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strcpy(char *dst, const char *src);
int mx_strcmp(const char *s1, const char *s2);
char* mx_strcat(char* s1, const char* s2);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
int mx_strlen(const char *s);
bool mx_isdigit(int c);
bool mx_isnumber(char *s);
bool mx_isspace(char c);
