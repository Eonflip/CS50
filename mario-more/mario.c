#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int column;
    int linenum;

    do
    {
       height = get_int("Height: ");
    }
    while (height < 1 && height > 8);

    for (int i = 0; i < height; i++) {

        for (int j = 0; j < height - i - 1; j++)
            printf(" ");
        for (int j = 0; j < i + 1; j++)
            printf("#");
        for (int j = 0; j < 3; j++)
            printf(" ");
        for (int j = 0; j < i + 1; j++)
            printf("#");
        for (int j = 0; j < height - i - 1; j++)
            printf(" ");

        printf("\n");
    }



}