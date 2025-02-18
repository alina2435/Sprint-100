#include "file_to_str.h"

static char *try_cpy(const char *src);

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    else if (s1 == NULL) {
        return try_cpy(s2);
    }
    else if (s2 == NULL) {
        return try_cpy(s1);
    }

    char *cpy = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    mx_strcpy(cpy, s1);

    if (!cpy) {
        return NULL;
    }

    return mx_strcat(cpy, s2);
}

static char *try_cpy(const char *src) {
    char *new = mx_strnew(mx_strlen(src));

    if (!new) {
        return NULL;
    }

    return mx_strcpy(new, src);
}
