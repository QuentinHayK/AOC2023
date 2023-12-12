#define _POSIX_C_SOURCE 200809L
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *color[] = { "red", "green", "blue" };
static const size_t size[] = { 3, 5, 4 };

int main(void)
{
    FILE *fs = fopen("input", "r");
    size_t len = 0;
    char *line = NULL;

    size_t res = 0;
    while (getline(&line, &len, fs) != -1)
    {
        ssize_t i = 7;
        size_t c[3] = { 0, 0, 0 };
        while (line[i] != '\n')
        {
            while (!isdigit(line[i]))
                i++;

            size_t n = 0;
            while (isdigit(line[i]))
            {
                n = n * 10 - '0' + line[i];
                i++;
            }

            i++;
            for (int j = 0; j < 3; j++)
                if (!strncmp(line + i, color[j], size[j]))
                {
                    if (c[j] < n)
                        c[j] = n;

                    i += size[j];
                    break;
                }
        }

        res += c[0] * c[1] * c[2];
    }

    printf("%lu\n", res);
    free(line);
    fclose(fs);

    return 0;
}
