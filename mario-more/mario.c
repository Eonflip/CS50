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

    for (int i = 1; i <= height - 1; i++)
    {
        for (int j = 1; j <= height - 1; j++)
        {
            printf(" ");
        }
        printf(" ");
        printf("#\n");
    }
}