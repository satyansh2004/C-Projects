#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    int roll;
    char name[50];
    float marks;
} std;

float average_marks(std *student, int number_students)
{
    float sum = 0;
    for (int i = 0; i < number_students; i++)
    {
        sum = sum + student->marks;
    }

    int average = sum / number_students;

    return average;
}

void print_topper(std *student, int number_students)
{
    for (int i = 0; i < number_students; i++)
    {
        float max = student[i].marks;
        for (int j = i; j < number_students + 1; j++)
        {
            if (student[i].marks > max)
            {
                max = student[i].marks;
                printf("Max num: %f\n", max);
            }
            else
            {
                printf("Else Max num: %f\n", max);
            }
        }
    }
}

int main(void)
{

    int number_students;

    printf("Enter number of students: ");
    scanf("%d", &number_students);

    struct Student *std_ptr = (struct Student *)malloc(number_students * sizeof(struct Student));
    for (int i = 0; i < number_students; i++)
    {
        int roll;

        char name[50];

        float marks;

        printf("\nStudent %d name: ", i + 1);
        scanf("%s", &name);

        printf("Student (%s) roll number: ", name);
        scanf("%d", &roll);

        printf("Student (%s) marks: ", name);
        scanf("%f", &marks);

        snprintf(std_ptr[i].name, sizeof(std_ptr[i].name), "%s", name);
        std_ptr[i].roll = roll;
        std_ptr[i].marks = marks;
    }

    printf("\n");
    // for (int i = 0; i < number_students; i++)
    // {
    //     printf("\nName: %s\nRoll: %d\nMarks: %.2f", (*std_ptr).name, (*std_ptr).roll, (*std_ptr).marks);
    //     printf("\n");
    //     std_ptr++;
    // }
    // float a = average_marks(std_ptr, number_students);
    // printf("Average Marks: %.2f", a);
    print_topper(std_ptr, number_students);

    // free(std_ptr);

    return 0;
}