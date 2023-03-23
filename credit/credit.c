#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int validate(long n);
long get_cc();

int main(void)
{
   switch (validate(get_cc()))
    {
        case 3:
            printf("AMEX\n");
            break;
        case 4:
            printf("VISA\n");
            break;
        case 5:
            printf("MASTERCARD\n");
            break;
        case 6:
            printf("DISCOVER\n");
            break;
        default:
            printf("INVALID\n");
    }

}


long get_cc()
{
    long n;
    do
    {
        n = get_long("Enter a credit card number: ");
    }
    while (n < 0 || n > 50000000000000000);
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
            temp = temp - 9;
        }
        sum += temp;
        number /= 10;
        temp = number % 10;
        sum += temp;
        number /= 10;
    }

    while (n > 100)
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
