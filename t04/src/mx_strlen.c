#include "../inc/str_utils.h"

int mx_strlen(const char *s) {
    int len = 0;

    for (; *(s + len) != '\0'; len++) {}

    return len;
}
