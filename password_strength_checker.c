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

bool containInt(char password[], int nums[])
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
    int length = checkLength(password);
    for (int i = 0; i < length; i++)
    {
        char ch = password[i];
        int asciiValue = (int)ch;
        for (int j = 65; j <= 90; j++)
        {
            if (asciiValue == j)
            {
                return true;
                goto end;
            }
        }
    }
end:

    return false;
}

bool containsLowerCase(char password[])
{
    int length = checkLength(password);
    for (int i = 0; i < length; i++)
    {
        char ch = password[i];
        int asciiValue = (int)ch;
        for (int j = 97; j <= 122; j++)
        {
            if (asciiValue == j)
            {
                return true;
                goto end;
            }
        }
    }
end:

    return false;
}

bool hasSymbols(char password[])
{
    int length = checkLength(password);
    for (int i = 0; i < length; i++)
    {
        char ch = password[i];
        int asciiValue = (int)ch;
        for (int j = 35; j <= 38; j++)
        {
            if (asciiValue == j || asciiValue == 64)
            {
                return true;
                goto end;
            }
        }
    }
end:

    return false;
}

int scoringPassword(int, int, int, int, int);
int main(void)
{
    char password[20];
    int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Enter password: ");
    fgets(password, 20, stdin);

    int length = checkLength(password);                 // Return Length
    int digitContainCheck = containInt(password, nums); // Return true (1) or false (0)
    int hasUpperCase = containsUpperCase(password);     // Return true (1) or false (0)
    int hasLowerCase = containsLowerCase(password);     // Return true (1) or false (0)
    int doesHasSymbols = hasSymbols(password);          // Return true (1) or false (0)

    int passwordScore = scoringPassword(length, digitContainCheck, hasUpperCase, hasLowerCase, doesHasSymbols);

    if (passwordScore < 10)
    {
        printf("\nPassword Strength: Weak");
    }
    if (passwordScore > 10 && passwordScore <= 20)
    {
        printf("\nPassword Strength: Medium");
    }
    if (passwordScore > 20)
    {
        printf("\nPassword Strength: Strong");
    }
}

int scoringPassword(int length, int digitContainCheck, int hasUpperCase, int hasLowerCase, int doesHasSymbols)
{
    int score = 0;

    if (length >= 8)
        score = score + 5;
    if (digitContainCheck == 1)
        score = score + 5;
    if (hasUpperCase)
        score = score + 5;
    if (hasLowerCase)
        score = score + 5;
    if (doesHasSymbols)
        score = score + 5;

    return score;
}