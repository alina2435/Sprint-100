#include "../inc/str_utils.h"

char *mx_skip_spaces(char *str) {
    if (!str) return NULL;
    while (*str && mx_isspace(*str)) {
        str++;
    }
    return str;
}
