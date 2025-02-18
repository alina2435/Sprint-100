#include "minilibmx.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        char buf[1024];
        int n;
        while ((n = read(0, buf, sizeof(buf))) > 0)
        {
            write(1, buf, n);
        }
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        int file = open(argv[i], O_RDONLY);
        if (file < 0)
        {
            mx_printerr("mx_cat: ");
            mx_printerr(argv[i]);
            mx_printerr(": ");
            mx_printerr(strerror(errno));
            mx_printerr("\n");
            continue;
        }

        char buf[1024];
        int n;
        while ((n = read(file, buf, sizeof(buf))) > 0)
        {
            write(1, buf, n);
        }

        close(file);
    }
    return 0;
}
