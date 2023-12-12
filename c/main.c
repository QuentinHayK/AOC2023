#define _POSIX_C_SOURCE 200809L
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fs = fopen("input", "r");
    size_t len = 0;
    char *line = NULL;

    ssize_t s = 0;
    while ((s = getline(&line, &len, fs)) != -1)
    {
    }

    free(line);
    fclose(fs);

    return 0;
}
