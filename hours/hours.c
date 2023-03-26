#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    //initialize sum to add up total hours
    int sum = 0;

    //for loop to access and add to sum hours of each week in array hours[]
    for (int i = 0; i < weeks; i++)
    {
        sum += hours[i];
    }
    //if else loops to determine if total or average and which arithmetic to perform
    if (output == 'T')
    {
        return sum;
    }
    else
    {
        return (float) sum / (float) weeks;
    }
}