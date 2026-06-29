#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
} std;

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
    for (int i = 0; i < number_students; i++)
    {
        printf("\nName: %s\nRoll: %d\nMarks: %.2f", (*std_ptr).name, (*std_ptr).roll, (*std_ptr).marks);
        printf("\n");
        std_ptr++;
    }
    free(std_ptr);

    return 0;
}