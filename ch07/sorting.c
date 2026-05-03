// sorting algorithms using pointers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10
void bubbleSort(int array[], size_t size);
void selectionSort(int array[], size_t size);
void printArray(int array[], size_t size);
void randomArrayInitialization(int array[], size_t size);

void randomArrayInitialization(int array[], size_t size)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        array[i] = rand() % 101;
    }
}


void printArray(int array[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void bubbleSort(int array[], size_t size)
{  
    bool swapped = false;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}
int main(void)
{
    int array[SIZE];
    randomArrayInitialization(array, SIZE);
    printArray(array, SIZE);
    bubbleSort(array, SIZE);
    printArray(array, SIZE);
    return 0;
}
