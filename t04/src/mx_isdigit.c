#include "../inc/str_utils.h"

bool mx_isdigit(int c) {
    return c >= '0'
        && c <= '9';
}

bool mx_isnumber(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (mx_isdigit(s[i])) {
            continue;
        }
        if (i == 0 && (s[i] == '+' || s[i] == '-')) {
            continue;
        }
        return false;
    }
    return true;
}

