#include "minilibmx.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        return 1;
    }

    int src = open(argv[1], O_RDONLY);
    if (src < 0)
    {
        mx_printerr("mx_cp: ");
        mx_printerr(argv[1]);
        mx_printerr(": ");
        mx_printerr(strerror(errno));
        mx_printerr("\n");
        return 1;
    }

    int dst = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (dst < 0)
    {
        mx_printerr("mx_cp: ");
        mx_printerr(argv[2]);
        mx_printerr(": File exists\n");
        close(src);
        return 1;
    }

    char buf[1024];
    int n;
    while ((n = read(src, buf, sizeof(buf))) > 0)
    {
        if (write(dst, buf, n) != n)
        {
            mx_printerr("error writing file\n");
            close(src);
            close(dst);
            return 1;
        }
    }
    if (n < 0)
    {
        mx_printerr("error reading file\n");
        close(src);
        close(dst);
        return 1;
    }
    close(src);
    close(dst);
    return 0;
}
