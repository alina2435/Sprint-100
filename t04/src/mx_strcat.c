#include "../inc/str_utils.h"

char* mx_strcat(char* s1, const char* s2) {
    int s1_len = mx_strlen(s1);
    int s2_len = mx_strlen(s2);

    for (int i = 0; i < s2_len; i++) {
        *(s1 + s1_len + i) = *(s2 + i);
    }

    *(s1 + s1_len + s2_len) = '\0';

    return s1;
}
