#include "file_to_str.h"

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
