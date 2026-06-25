#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <tchar.h>

int main(void)
{

    while (1)
    {
        char str[200];
        WIN32_FIND_DATA Findfiledata;
        HANDLE hFind;

        TCHAR targetDir[] = TEXT(".\\*");

        hFind = FindFirstFile(targetDir, &Findfiledata);

        printf("Enter the name of the file you want to change: ");
        fgets(str, sizeof(str), stdin);

        if (hFind == INVALID_HANDLE_VALUE)
        {
            printf("\nNo such files exists in directory");
        }
        else
        {
            do
            {
                if (Findfiledata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                {
                    continue;
                }
                else
                {
                    char newStr[200];
                    int i = 0;
                    while (str != '\0')
                    {
                        if (str[i] != '\t' && str[i] != '\n')
                        {
                            newStr[i] = str[i];
                            i = i + 1;
                        }
                    }
                    printf("Hello %s\n", newStr);
                    // if (strcmp(str, Findfiledata.cFileName) == 0)
                    // {
                    //     _tprintf(TEXT("[FILE] %s\n"), Findfiledata.cFileName);
                    // }
                }
            } while (FindNextFile(hFind, &Findfiledata) != 0);
            FindClose(hFind);
        }

        // printf("%s", str);
    }
    // MoveFile("Hello.txt", "Bye.txt");
    return 0;
}