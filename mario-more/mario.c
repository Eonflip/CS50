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

    for (int i = 1; i <= height; i++)
    {
        for (column = 1; column <= height; column++)
        {
            printf("#");
        }
        printf("\n");
        printf("#");
    }

}