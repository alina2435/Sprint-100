#include "../inc/str_utils.h"

void mx_del_strarr(char ***arr) {
    if (!arr || !*arr) return; 

    for (int i = 0; (*arr)[i]; i++) {
        mx_strdel(&((*arr)[i]));
    }

    free(*arr);
    *arr = NULL;
}
