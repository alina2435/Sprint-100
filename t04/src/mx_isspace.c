#include "../inc/str_utils.h"

bool mx_isspace(char c) {
    return c == ' '
        || c == '\t'
        || c == '\v'
        || c == '\f'
        || c == '\n'
        || c == '\r';
}
