# include <stdio.h>

int main(void)
{
    int grade1 = 0;
    int grade2=0;
    int grade3=0;
    int average=0;
    int temp_grade = 0;

    scanf("%d", &temp_grade);
    if (temp_grade >50)
    {
        grade1 = temp_grade;
    }
    scanf("%d", &temp_grade);
    if (temp_grade >50)
    {
        grade2 = temp_grade;
    }
    scanf("%d", &temp_grade);
    if 
    (temp_grade >50)
    {
        grade3 = temp_grade;
    }
    average = (grade1 + grade2 + grade3) / 3;
    printf("The average of the three grades is %d\n", average);
    return 0;
}