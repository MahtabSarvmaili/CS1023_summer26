# include <stdio.h>
# include <ctype.h>

#define SIZE 10

void convertToUpperCase(char *sPtr);
void printStringArray(char array[], size_t size);
void inputStringArray(char arra[], size_t size);

void printStringArray(char array[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%c", array[i]); 
    }
    printf("\n");
}

void inputStringArray(char array[], size_t size)
{
    puts("Enter a string: ");
    for (size_t i = 0; i < size; i++)
    {
        printf("Enter the character %zu-th of the array: ", i);
        scanf(" %c", &array[i]); // space before %c to skip newlines and spaces
        if (array[i] == '\0')
        {
            break;
        }
    }
}


void convertToUpperCase(char *sPtr)
{

    *sPtr = toupper(*sPtr);

}

int main(void)
{
    char string[SIZE];
    inputStringArray(string, SIZE);
    printStringArray(string, SIZE);
    for (size_t i=0; i<SIZE; i++)
    {
        if (string[i] == '\0')
        {
            break;
        }
        convertToUpperCase(&string[i]);
    }
    printStringArray(string, SIZE);
    return 0;
}