#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int validate(long n);

int main(void)
{

}


int validate(long n)
{
    long number = n;
    int sum = 0;

    printf("Number: %ld\n", number);


    sum = number % 10;
    number = number / 10;
    while(number)
    {
        int temp = (number % 10) * 2;
        if (temp > 9)
        {
            temp = temp - 9
        }
        sum = sum + temp 
    }
}
