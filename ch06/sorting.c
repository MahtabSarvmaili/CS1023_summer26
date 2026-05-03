#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define SIZE 10
/*  
This file contains the Bubble Sort & Selection Sort implementations.
*/

void bubbleSort(int array[], size_t size);
void selectionSort(int array[], size_t size);
void printArray(int array[], size_t size);

void printArray(int array[], size_t size)
{
    printf("Elements of the array: ");
    for (size_t i=0; i<size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(void)
{
    int b_array[SIZE];
    int s_array[SIZE];

    puts("Random initialization of the array.\n");
    // seeding the random number generator
    srand((unsigned) time(NULL)); 
    // initializing the array with random integers between 0 - 100

    for (size_t i=0;i<SIZE; i++)
    {
        b_array[i] = rand() % 101;
        s_array[i] = rand() % 101;
    }
    
    printf("Elements of the array before sorting: ");
    printArray(b_array, SIZE);
    bubbleSort(b_array, SIZE);
    selectionSort(s_array, SIZE);
    printf("Elements of the array after bubble sort: ");
    printArray(b_array, SIZE);
    printf("Elements of the array after selection sort: ");
    printArray(s_array, SIZE);

}



void bubbleSort(int array[], size_t size)
{
    puts("Bubble Sort with in-place swapping...");
    bool swapped;
    for (size_t i=0; i<size-1;i++)
    {
        swapped = false;
        for (size_t j=0; j<size-1-i; j++)
        {
            if (array[j] > array[j+1])
            {
                // in function swap
                int temp =array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }

    }
}


void selectionSort(int array[], size_t size)
{
    puts("Selection Sort with in-place swapping...");
    for (size_t i=0; i<size-1; i++)
    {
        for (size_t j=i+1; j<size; j++){
            if (array[i]> array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}