#include <cs50.h>
#include <stdio.h>

void pyramids(int h);
void print_pyramids(int h, int w);

int main(void)
{
    int h = 0;
    do
    {
        h = get_int("Height: ");
    }
    while (1 > h || h > 8);

    pyramids(h);
}

void pyramids(int h)
{
    int w = 0;
    w = h - 1;
    while (0 <= w)
    {
        print_pyramids(h, w);
        w--;
    }
}

void print_pyramids(int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        if (i < w)
        {
            printf(" ");
        }
        else
        {
            printf("#");
        }
    }

    w = h - w;
    printf("  ");
    for (int i = 0; i < w; i++)
    {
        printf("#");
    }
    printf("\n");
}
