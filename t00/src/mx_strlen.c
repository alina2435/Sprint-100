#include "minilibmx.h"

int mx_strlen(const char *s)
{
    int z = 0;
    while (s[z] != '\0')
        z++;
    return z;
}
