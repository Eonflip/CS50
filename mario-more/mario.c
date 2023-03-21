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

    for (int i = 0; i < height - 1; i++)
    {
        printf(" ");
        printf("#\n");
        for (int j = 0; j < height; j++)
        {
            printf("#");
        }
    }
}