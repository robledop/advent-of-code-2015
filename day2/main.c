#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    --- Day 2: I Was Told There Would Be No Math ---
    The elves are running low on wrapping paper, and so they need to submit an order for more.
    They have a list of the dimensions (length l, width w, and height h) of each present, and
    only want to order exactly as much as they need.

    Fortunately, every present is a box (a perfect right rectangular prism), which makes calculating
     the required wrapping paper for each gift a little easier: find the surface area of the box,
      which is 2*l*w + 2*w*h + 2*h*l. The elves also need a little extra paper for each present:
      the area of the smallest side.

    For example:

    A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet of wrapping
    paper plus 6 square feet of slack, for a total of 58 square feet.
    A present with dimensions 1x1x10 requires 2*1 + 2*10 + 2*10 = 42 square feet of wrapping
     paper plus 1 square foot of slack, for a total of 43 square feet.
    All numbers in the elves' list are in feet. How many total square feet of wrapping paper
    should they order?
*/

int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    FILE *text_file;
    text_file = fopen("input1.txt", "r");

    size_t total_paper_area = 0;
    while (getline(&line, &len, text_file) != -1)
    {
        int length = atoi(strtok(line, "x"));
        int width = atoi(strtok(NULL, "x"));
        int height = atoi(strtok(NULL, "x"));

        size_t area1 = (2 * length * width);
        size_t area2 = (2 * width * height);
        size_t area3 = (2 * height * length);
        size_t box_surface_area = area1 + area2 + area3;

        int smallest_side = 0;

        if (area1 < area2 && area1 < area3)
        {
            smallest_side = area1 / 2;
        }
        else if (area2 < area3)
        {
            smallest_side = area2 / 2;
        }
        else
        {
            smallest_side = area3 / 2;
        }

        size_t paper_area = box_surface_area + (smallest_side);

        total_paper_area += paper_area;
    }

    printf("Total paper area: %zu square feet\n", total_paper_area);
}