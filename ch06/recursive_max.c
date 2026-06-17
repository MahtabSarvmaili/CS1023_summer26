#include <stdio.h>

// Recursive function to find maximum element in an array
int findMax(int arr[], int size)
{
    // Base case: only one element
    if (size == 1)
    {
        return arr[0];
    }

    // Recursive call: find max in remaining array
    int maxOfRest = findMax(arr, size - 1);

    // Compare last element with max of previous elements
    if (arr[size - 1] > maxOfRest)
    {
        return arr[size - 1];
    }
    else
    {
        return maxOfRest;
    }
}

int main()
{
    int numbers[] = {12, 7, 25, 3, 18, 40, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int max = findMax(numbers, size);

    printf("Maximum value: %d\n", max);

    return 0;
}