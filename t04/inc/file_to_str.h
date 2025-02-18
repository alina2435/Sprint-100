#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

#include "str_utils.h"

#define BUFF_SIZE 2048

char *mx_file_to_str(const char *filename);
