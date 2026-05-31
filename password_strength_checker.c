#include <stdio.h>
#include <stdbool.h>

int checkLength(char password[])
{
    int i = 0;
    while (password[i] != '\0')
    {
        i++;
    }
    return i - 1;
}

bool containDigit(char password[], int nums[])
{
    int length = checkLength(password);

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            char ch = password[i];
            int n = ch - '0';
            if (n == nums[j])
            {
                return true;
                break;
            }
        }
    }

    return false;
}

bool containsUpperCase(char password[])
{
    return false;
}

int main(void)
{
    char password[20];
    int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Enter password: ");
    fgets(password, 20, stdin);

    int length = checkLength(password);                   // Return Length
    int digitContainCheck = containDigit(password, nums); // Return true (1) or false (0)
}