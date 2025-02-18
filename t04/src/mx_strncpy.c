#include "../inc/str_utils.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    if (len < 0) {
        return dst;
    }

    for (int i = 0; i < len; i++) {
        *(dst + i) = *(src + i);
        if (!*(src + i)) {
            break;
        }
    }

    *(dst + len) = '\0';

    return dst;
}
