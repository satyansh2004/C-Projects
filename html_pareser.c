/*
This is a simple html parser which extarcts texts from single tags like:
-> h1 - h6
-> p
-> span etc.
*/

#include <stdio.h>

char parser(char *input)
{
    char *ptr = input;
    char parsedText[100];
    char *parsedPtr = parsedText;

    int i = 0;
    int count = 0, endStr = 0;
    while (*ptr != '\0')
    {
        if (*ptr == '>')
        {
            count = i;
        }
        if (*ptr == '<' && *(ptr + 1) == '/')
        {

            goto end;
            *(ptr - 1) = '\0';
        }
        else
        {
            endStr++;
            *parsedPtr = *ptr;
            *parsedPtr++;
        }

        ptr++;
        i++;
    }

end:
    parsedPtr = parsedText;
    for (int i = 0; i < count + 1; i++)
    {
        parsedPtr++;
    }
    for (int i = 0; i < endStr - 2; i++)
    {
        if (*parsedPtr == ' ' && (i == 0 || i == endStr + 1))
        {
            parsedPtr++;
        }

        printf("%c", *parsedPtr);
        parsedPtr++;
    }
}

int main(void)
{
    char input[100] = "<p> This is headings a hi my name is satyansh</p>";
    parser(input);
    return 0;
}