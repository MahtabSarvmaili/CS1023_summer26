#include <stdio.h>
# define SIZE 10
# define RATING 5


enum color {RED, GREEN, BLUE};
static const int ARRAY_SIZE = 5;

int processResponse(void);
void barChart(int responses[], int num_students);
int testArray(void);
void staticArrayInit(void); 
void ModifyArray(int array[], size_t size); 


void printingArray(int array[], size_t size)
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
    //pre-assigned array of integers
    int a[SIZE]={0};
    
    // inline for loop to print the elements of the array
    printf("Elements of array a: ");
    printingArray(a, SIZE);
    ModifyArray(a, SIZE);
    printingArray(a, SIZE);

    testArray();
    puts("Testing array input...");
    testArray();
    // processResponse()
    puts("Processing responses...");
    processResponse();


    // testing static array initialization
    puts("Testing static array during multiple calls to the function!");
    staticArrayInit();
    staticArrayInit(); // call again to see the effect of static storage duration
    

}

int testArray(void)
{
    int b[ARRAY_SIZE];
    for (size_t i=0; i<ARRAY_SIZE; i++)
    {   
        printf("Enter the item %zu-th of array b: ", i);
        scanf("%d", &b[i]);
        printf("b[%zu] = %d\n", i, b[i]);
    }
    return 0;
}


int processResponse(void)
{
    int num_students;
    printf("Enter the number of students who responded: ");
    scanf("%d", &num_students);

    int responses[num_students];
    int answer_frequency[RATING] = {0};

    for (size_t i=0; i<num_students; i++)
    {
        printf("Enter the rating (0-%d) for student %zu: ", RATING-1, i);
        scanf("%d", &responses[i]);
        // important consideration: if the input ratings are larger than RATING, then we will have an out-of-bounds access to the answer_frequency array,
        // which can lead to undefined behavior. In a production code, we should add input validation to ensure that the ratings are within the expected range.
        ++answer_frequency[responses[i]];
    }
    printf("Rating\tFrequency\n");
    for (size_t i=0; i<RATING; i++)
    {
        printf("%zu\t%d\n", i, answer_frequency[i]);
    }

    printf("PLOTTING BAR CHART...\n");
    barChart(responses, num_students);
    return 0;

}


void barChart(int responses[], int num_students)
{
    printf("Element \t Rating Value \t Bar Chart\n");
    printf("--------\t--------\t.  ---------\n");
    for (int i=0; i<num_students;i++)
    {
        printf("%d\t %d\t", i, responses[i]);
        for (int j =0; j<responses[i]; j++)
        {
            printf("*");
        }
        printf("\n"); 
    }
}



void staticArrayInit(void)
{
/*
This is a very common confusion. The key point is:

static does NOT mean "cannot change"
It means "initialized once and keeps its value between function calls" 🔁

Let's break it down precisely.

The Important Part — Call Function Again

If you call:

staticArrayInit();
staticArrayInit();

Then:

First Call

Entering:

0 0 0

Exiting:

5 5 5
Second Call

Now entering values are:

5 5 5

Then modified again:

10 10 10

*/

    static int array[3];
    printf("Entering staticArrayInit:\n");
    for (size_t i = 0; i < 3; i++)
    {
        printf("array[%zu] = %d  ", i, array[i]);
    }
    printf("\nExiting staticArrayInit:\n");
    for (size_t i = 0; i < 3; i++)
    {
        printf("array[%zu] = %d  ", i, array[i] += 5);
    }
    printf("\n");
}


void ModifyArray(int array[], size_t size)
{
    puts("Modifying array by adding 5 to each element...");
    for (size_t i=0; i< size; i++)
    {
        array[i] += 5;
    }
}