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
        case 34:
            printf("AMEX\n");
            break;
         case 37:
            printf("AMEX\n");
            break;
         case 40:
            printf("VISA\n");
            break;
        case 41:
            printf("VISA\n");
            break;
        case 42:
            printf("VISA\n");
            break;
        case 43:
            printf("VISA\n");
            break;
        case 44:
            printf("VISA\n");
            break;
        case 45:
            printf("VISA\n");
            break;
        case 46:
            printf("VISA\n");
            break;
        case 47:
            printf("VISA\n");
            break;
        case 48:
            printf("VISA\n");
            break;
        case 49:
            printf("VISA\n");
            break;
        case 51:
            printf("MASTERCARD\n");
            break;
        case 52:
            printf("MASTERCARD\n");
            break;
        case 53:
            printf("MASTERCARD\n");
            break;
        case 54:
            printf("MASTERCARD\n");
            break;
        case 55:
            printf("MASTERCARD\n");
            break;
        default:
            printf("INVALID\n");
    }

}


long get_cc()
{
    long n = 0;
    do
    {
        n = get_long("Enter a credit card number: ");
    }
    while (n < 0 || n > 50000000000000000);

    if (floor(log10(labs(n))) + 1 == 13 || floor(log10(labs(n))) + 1 == 15 || floor(log10(labs(n))) + 1 == 16)
    {
        printf("%f", floor(log10(labs(n))) + 1);
        return nan;
    }



    return n;



}

int validate(long n)
{

    long number = n;
    int sum = 0;

    //printf("Number: %ld\n", number);


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


    //printf("Sum: %d\nLeftmost: %ld\n", sum, n);

    if (floor(log10(labs(n))) + 1 != 13 || floor(log10(labs(n))) + 1 != 15 || floor(log10(labs(n))) + 1 != 16 || sum % 10 )
    {
        printf("%ld\n", floor(log10(labs(n))) + 1);
        return -1;
    }
    return n;
}
