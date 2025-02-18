#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int mx_strlen(const char *s);
void mx_printerr(const char *s);

#endif
