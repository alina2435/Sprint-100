#include "../inc/str_utils.h"

static int *get_lens(const char *str, char delimiter, int len) {
    int word_index = 0;
    int *lens = malloc(sizeof(int) * len);

    while (*str) {
        if (*str == delimiter) {
            str++;
            continue;
        }

        lens[word_index] = 0;

        while (*str && *str != delimiter) {
            lens[word_index]++;
            str++;
        }
        word_index++;
    }

    return lens;
}

static char *next_word(const char *str, char delimiter) {
    while (*str) {
        if (*str != delimiter) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char **mx_strsplit(char const *s, char c) {
    if (!s) return NULL;
    int len = mx_count_words(s, c);
    if (len == 0) return NULL;
    char **arr = malloc((len + 1) * sizeof(char*));
    if (!arr) return NULL;
    arr[len] = NULL;
    int *lens = get_lens(s, c, len);
    char *next = next_word(s, c);

    for (int i = 0; i < len; i++) {
        arr[i] = mx_strnew(lens[i]);
        arr[i] = mx_strncpy(arr[i], next, lens[i]);
        next = next_word(next + lens[i], c);
    }

    arr[len] = NULL;

    free(lens);

    return arr;
}
