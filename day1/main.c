#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    FILE *textfile;
    int floor = 0;
    int current_position = 1;
    bool found = false;
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

        if (floor == -1 && !found)
        {
            found = true;
            printf("First went into the basement at position: %d\n", current_position);
        }

        current_position++;
    }

    printf("Ended up at floor: %d\n", floor);

    fclose(textfile);
}