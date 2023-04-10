// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    //initialize the max_num as the first element in the passed array (this may or may not change later)
    int max_num = array[0];

    //write a selection sort loop without changing the position of the array element once it's found to not be in the right place
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] > max_num)
            {
                max_num = array[j];
            }
        }

    }
    return max_num;
    return 0;
}
