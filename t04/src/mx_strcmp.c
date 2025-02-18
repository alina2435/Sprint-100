#include "../inc/str_utils.h"

int mx_strcmp(const char *s1, const char *s2) {
    char curr_s1 = *s1;
    char curr_s2 = *s2;
    int len = 0;

    while (curr_s1 || curr_s2) {
        curr_s1 = curr_s1 ? *(s1 + len) : curr_s1;
        curr_s2 = curr_s2 ? *(s2 + len) : curr_s2;

        if (curr_s1 != curr_s2) {
            return curr_s1 - curr_s2;
        }

        len++;
    }

    return 0;
}
