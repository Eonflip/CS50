#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int validate(long n);

int main(void)
{

}


long get_cc()
{
    printf("Enter a credit card number: ");
    long n;
    scanf("%ld", &n);\
    return n;
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
        sum = sum + temp;
        number = number / 10;
        temp = number % 10;
        sum = sum + temp;
        number = number / 10;
    }

    while (n > 10)
    {
        n = n / 10;
    }


    printf("Sum: %d\nLeftmost: %ld\n", sum, n);

    if (sum % 10)
    {
        return -1;
    }
    return n;
}
