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

float max = 0.00;
char topper_name[50];
void print_topper(std *students, int number_students)
{
    for (int i = 0; i < number_students; i++)
    {
        for (int j = 0; j < number_students; j++)
        {
            if (students[i].marks > students[j].marks)
            {
                max = students[i].marks;
                strcpy(topper_name, students[i].name);
            }
        }
    }

    printf("\nTopper name: %s\nTopper marks: %.2f", topper_name, max);
}

int main(void)
{

    int number_students;

    printf("Enter number of students: ");
    scanf("%d", &number_students);

    struct Student *std_ptr = (struct Student *)malloc(number_students * sizeof(struct Student));

    struct Student *temp = std_ptr;
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

    printf("\n________All Students________");
    for (int i = 0; i < number_students; i++)
    {
        printf("\nName: %s\nRoll: %d\nMarks: %.2f", (*temp).name, (*temp).roll, (*temp).marks);
        printf("\n");
        temp++;
    }
    float a = average_marks(std_ptr, number_students);
    printf("\nAverage Marks: %.2f\n", a);
    print_topper(std_ptr, number_students);

    free(std_ptr);

    return 0;
}