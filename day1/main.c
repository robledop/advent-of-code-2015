#include <stdio.h>

int main(void)
{
    FILE *textfile;
    int floor = 0;
    char c;
    textfile = fopen("input.txt", "r");

    while ((c = fgetc(textfile)) != EOF)
    {
        if (c == '(')
        {
            ++floor;
        }

        if (c == ')')
        {
            --floor;
        }
    }

    printf("Floor: %d\n", floor);

    fclose(textfile);
}