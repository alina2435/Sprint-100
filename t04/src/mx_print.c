#include "../inc/print.h"

static inline int local_abs(int n) {
    return n * ((n < 0)
            ? -1
            : 1);
}

void mx_printchar(char c) {
    write(1, &c, sizeof(char));
}

void mx_printstr(const char *s) {
    write(1, s, mx_strlen(s));
}

void mx_printerr(const char *s) {
    if (!s) return;
    write(2, s, mx_strlen(s));
}

void mx_printint(int n) {
    if (n < 0) {
        mx_printchar('-');
    }

    if (n / 10) {
        mx_printint(local_abs(n / 10)); 
    }

    mx_printchar(local_abs(n % 10) + 48);
}

