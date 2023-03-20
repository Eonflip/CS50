#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
       height = get_int("Height: \n");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        printf(" ") * (height - i);
        printf("#") * i;
        printf("  ");
        printf("#") * i;
        printf(" ") * (height - i);
        printf("\n");
    }

}