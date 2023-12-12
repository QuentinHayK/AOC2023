#define _POSIX_C_SOURCE 200809L
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int my_atoi(char *line, int i, int step)
{
    int n = 0;
    for (; i >= 0 && line[i] != '\n' && isdigit(line[i]); i += step)
        n = n * 10 + line[i] - '0';

    return n;
}

static inline int is_sym(const char c)
{
    return !isdigit(c) && c != '.';
}

int main(void)
{
    FILE *fs = fopen("input", "r");
    size_t acc = 0;
    int n = 0;
    size_t l1 = 0, l2 = 0, l3 = 0;
    char *up = NULL, *mid = NULL, *down = NULL;
    getline(&up, &l1, fs);
    getline(&mid, &l2, fs);
    int sym = 0;
    for (size_t i = 0; up[i] != '\n'; i++)
    {
        if (isdigit(up[i]))
        {
            n = n * 10 + up[i] - '0';
            sym = sym || is_sym(mid[i]);
        }
        else
        {
            if (is_sym())
        }
    }

    ssize_t s = 0;
    while ((s = getline(&down, &l3, fs)) != -1)
    {
        for (size_t i = 0; mid[i] != '\n'; i++)
        {
        }
    }

    free(line);
    fclose(fs);

    return 0;
}
