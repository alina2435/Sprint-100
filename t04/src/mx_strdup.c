#include "../inc/str_utils.h"

char *mx_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    char *clone = mx_strnew(mx_strlen(str));

    if (!clone) {
        return NULL;
    }

    return mx_strcpy(clone, str);
}
