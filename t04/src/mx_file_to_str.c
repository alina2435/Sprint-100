#include "../inc/file_to_str.h"

char *mx_file_to_str(const char *filename) {
    int fd = open(filename, O_RDWR);
    if (fd == -1) return NULL;
    char *str = NULL;
    char *buf = mx_strnew(BUFF_SIZE);

    while (read(fd, buf, BUFF_SIZE) > 0) {
        if (!buf) {
            close(fd);
            free(str);
            return NULL;
        }
        str = mx_strjoin(str, buf);
        if (!str) {
            close(fd);
            free(buf);
            return NULL;
        }
    }

    free(buf);
    close(fd);
    return str;
}
