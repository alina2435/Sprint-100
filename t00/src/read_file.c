#include "minilibmx.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        mx_printerr("usage: ./read_file [file_path]\n");
        return 1;
    }

    int file = open(argv[1], O_RDONLY);
    if (file == -1)
    {
        mx_printerr("error\n");
        return 1;
    }

    char buf[1024];
    int n;
    while ((n = read(file, buf, sizeof(buf))) > 0)
    {
        write(1, buf, n);
    }

    if (n < 0)
    {
        mx_printerr("error\n");
        close(file);
        return 1;
    }

    close(file);
    return 0;
}
