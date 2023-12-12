#define _POSIX_C_SOURCE 200809L #include<ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int read_digit(const char *line)
{
    if (!strncmp("one", line, 3))
        return 1;
    if (!strncmp("two", line, 3))
        return 2;
    if (!strncmp("three", line, 5))
        return 3;
    if (!strncmp("four", line, 4))
        return 4;
    if (!strncmp("five", line, 4))
        return 5;
    if (!strncmp("six", line, 3))
        return 6;
    if (!strncmp("seven", line, 5))
        return 7;
    if (!strncmp("eight", line, 5))
        return 8;
    if (!strncmp("nine", line, 4))
        return 9;

    return 0;
}

int main(void)
{
    FILE *fs = fopen("input.txt", "r");
    size_t len = 0;
    char *line;

    ssize_t s = 0;
    size_t acc = 0;
    while ((s = getline(&line, &len, fs)) != -1)
    {
        if (s < 2)
            continue;

        size_t i = 0;
        size_t u = 0;
        // Get first digit
        while (u == 0)
        {
            u = read_digit(line + i);
            if (isdigit(line[i]))
                u = line[i] - '0';

            i++;
        }

        size_t n = u * 10;
        while (line[i] != '\n')
        {
            if (read_digit(line + i))
                u = read_digit(line + i);
            if (isdigit(line[i]))
                u = line[i] - '0';

            i++;
        }

        n += u;
        acc += n;
    }

    free(line);
    printf("%lu\n", acc);
    fclose(fs);

    return 0;
}
