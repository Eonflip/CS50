#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

long num = 0;

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int temp_num = 0;
    int counter = strlen(input);

    if (counter == 0)
    {
        return num;
    }

    for (int i = counter - 1; i >= 0; i--)
    {
        temp_num = input[i] - '0';
        input[i] = '\0';
        convert(input);
        num = num * 10 + temp_num;
    }
    return temp_num;


}