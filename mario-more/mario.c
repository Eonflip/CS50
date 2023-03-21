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
    while (height < 1 || height > 8);


    for (linenum = height; linenum >= 0; linenum--)
    {
        for (column = height; column < linenum; column++)
        {
            printf("#");
        }
     printf("\n");
    }




    for (linenum = 1; linenum <= height; linenum++)
    {
      for (column = 0; column < linenum; column++)
      {
           printf("#");
      }
     printf("\n");
    }
}