#include "../inc/atoi.h"

int mx_atoi(const char *src) {
    int out = 0;
    int i = 0;
    bool makeNegative = false;

    for (; *(src + i) && mx_isspace(*(src + i)); i++);

    if (*(src + i) == '-') {
        makeNegative = true;
        i++;
    } else if (*(src + i) == '+') {
        i++;
    }

    for (int j = i; *(src + j) && mx_isdigit(*(src + j)); j++) {
        out = out * 10 + *(src + j) - 48;
    }

    return makeNegative ? -out : out;
}
