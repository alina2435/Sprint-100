#include "../inc/str_utils.h"

int mx_count_words(const char *str, char delimiter) {
    char *s = (char *)str;
    int word_count = 0;

    while (*s) {
        if (*s == delimiter) {
            s++;
            continue;
        }

        word_count++;

        while (*s && *s != delimiter) {
            s++;
        }
    }

    return word_count;
}
