#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int column;

    do
    {
       height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; height++)
    {
        for (column = 0; column < height; column++)
        {
            printf("#");
        }
        printf("\n");
        printf("#");
    }

}