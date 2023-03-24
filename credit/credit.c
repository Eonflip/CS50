#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int validate(long n);
long get_cc();

int main(void)
{
//switch case statement to check what 2 numbers begin the card
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


//function to get the credit card number from user input and verify that it is the correct number of digits
long get_cc()
{
    long n = 0;
    do
    {
        n = get_long("Enter a credit card number: ");
    }
    while (n < 0 || n > 50000000000000000);

    int num_digits = floor(log10(labs(n))) + 1;

    //check to ensure that the card number is the correct number of digits
    if (num_digits == 13 || num_digits == 15 || num_digits == 16)
    {
        //test statement to print out the result of the num_digits int
        //printf("%d", num_digits);
        return n;
    }

    else
    {
        return -1;
    }



}


//checksum function
int validate(long n)
{

    long number = n;
    int sum = 0;

    //printf("Number: %ld\n", number);

    //take the end digit from the long n and add it to sum, divide by 10 to cut off the final digit
    sum = number % 10;
    number = number / 10;

    //while loop to mulitply every other number by 2 and add to sum all numbers and continue to cut the last digit off after adding
    while (number)
    {
        int temp = (number % 10) * 2;
        //if loop to combine any numbers that are 2 digits (ex. 8*2 = 16, 16-9 = 7 = 1 + 6)
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

    if (sum % 10)
    {
        return -1;
    }

    return n;
}
