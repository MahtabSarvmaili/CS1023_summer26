#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


# define SIZE 10

void bubbleSort(int array[], size_t size);
void linearSearch(int array[], size_t size, int key);
int binarySearch(int array[], int key, size_t low, size_t high);
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

void randomArray(int array[], size_t size)
{
    // seeding the random number generator
    srand((unsigned) time(NULL)); 
    // initializing the array with random integers between 0 - 100

    for (size_t i=0;i<size; i++)
    {
        array[i] = rand() % 101;
    }
}

void bubbleSort(int array[], size_t size)
{
    puts("Bubble Sort with in-place swapping...");
    bool swapped;
    for (size_t i=0; i< size-1; i++){
        swapped = false;
        for (size_t j=0; j<size-1-i; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j]= array[j+1];
                array[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}

int binarySearch(int array[], int key, size_t low, size_t high)
{
    puts("Performing binary search...");
    while (low <= high){
        size_t mid = (low+high)/2;
        if (array[mid] == key)
        {
            printf("Key %d found at index %zu in the array.\n", key, mid);
            return mid;
        }
        else if (array[mid] <key)
        {
            low = mid+1;
        }
        else
        {
            high = mid -1;
        }
    }
    return -1;
}

int binarySearchRecursive(int array[], int key, int low, int high)
{
    int mid = (low+high)/2;
    if (low > high)
    {
        printf("Key %d not found in the array.\n", key);
        return -1;
    }
    else if (array[mid]==key)
    {
        return mid;
    }
    else if (array[mid] > key)
    {
        return binarySearch(array, key, low, mid-1);
    }
    else
    {
        return binarySearch(array, key, mid+1, high);
    }
}


int main(void)
{

    int array[SIZE];
    randomArray(array, SIZE);
    printArray(array, SIZE);

    int key = array[(int) rand() % SIZE];
    bubbleSort(array, SIZE);
    printArray(array, SIZE);
    printf("Searching for the key %d in the array...\n", key);
    int result = binarySearch(array, key, 0, SIZE-1);
    printf("Result of binary search: %d\n", result);

    int result_recursive = binarySearchRecursive(array, key, 0, SIZE-1);
    printf("Result of recursive binary search: %d\n", result_recursive);

    printf("%p \n", &result);
    printf("%p \n", array);
    printf("%p \n", &array);
    printf("%p \n", &array[0]);
    int* p = &array[0];
    printf("%p \n", p);
}