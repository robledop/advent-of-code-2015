#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys/param.h"

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

/*
    --- Part Two ---
    The elves are also running low on ribbon. Ribbon is all the same width, so they only have
    to worry about the length they need to order, which they would again like to be exact.

    The ribbon required to wrap a present is the shortest distance around its sides, or the
    smallest perimeter of any one face. Each present also requires a bow made out of ribbon as
    well; the feet of ribbon required for the perfect bow is equal to the cubic feet of volume
    of the present. Don't ask how they tie the bow, though; they'll never tell.

    For example:

    A present with dimensions 2x3x4 requires 2+2+3+3 = 10 feet of ribbon to wrap the present
    plus 2*3*4 = 24 feet of ribbon for the bow, for a total of 34 feet.
    A present with dimensions 1x1x10 requires 1+1+1+1 = 4 feet of ribbon to wrap the present
    plus 1*1*10 = 10 feet of ribbon for the bow, for a total of 14 feet.
    How many total feet of ribbon should they order?
*/

int find_smallest(int a, int b, int c)
{
    if (a < b && a < c)
    {
        return a;
    }
    else if (b < c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

int find_second_smallest(int a, int b, int c)
{
    return MAX(MIN(a, b), MIN(MAX(a, b), c));
}

int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    FILE *text_file;
    text_file = fopen("input1.txt", "r");

    size_t total_paper_area = 0;
    size_t total_ribbon_length = 0;
    while (getline(&line, &len, text_file) != -1)
    {
        printf("%s", line);
        int length = atoi(strtok(line, "x"));
        int width = atoi(strtok(NULL, "x"));
        int height = atoi(strtok(NULL, "x"));

        size_t area1 = (2 * length * width);
        size_t area2 = (2 * width * height);
        size_t area3 = (2 * height * length);
        size_t box_surface_area = area1 + area2 + area3;

        int smallest_side = find_smallest(area1, area2, area3) / 2;

        size_t paper_area = box_surface_area + (smallest_side);

        total_paper_area += paper_area;

        int shortest_edge = find_smallest(length, width, height);
        printf("smallest edge: %d\n", shortest_edge);
        int second_shortest_edge = find_second_smallest(length, width, height);
        printf("second smallest edge: %d\n", second_shortest_edge);

        total_ribbon_length += (2 * shortest_edge) + (2 * second_shortest_edge) + (length * height * width);
    }

    printf("Total paper area: %zu square feet\n", total_paper_area);
    printf("Total ribbon length: %zu feet\n", total_ribbon_length);
}