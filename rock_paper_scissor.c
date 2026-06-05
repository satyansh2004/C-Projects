#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randomNumUpto3()
{
    srand(time(NULL));

label:
    int randomNum = rand() % (3 + 1);
    if (randomNum == 0)
    {
        goto label;
    }
    return randomNum;
}

int decison(int, int);

int main(void)
{
    int user_input, rounds, score = 0, robo_score = 0;

    for (;;)
    {
        printf("Game Started!\nChoose Number of rounds 3 or 5: ");
        scanf("%d", &rounds);
        if (rounds == 3)
        {
            break;
        }
        else if (rounds == 5)
        {
            break;
        }
    }

    for (int i = 0; i < rounds; i++)
    {
        for (;;)
        {
            printf("\nPick one:\nRock (Type: 1)\nPaper (Type: 2)\nScissor (Type: 3)\n\nYour Input: ");
            scanf("%d", &user_input);

            if (user_input == 1)
            {
                goto end_rounds;
            }
            else if (user_input == 2)
            {
                goto end_rounds;
            }
            else if (user_input == 3)
            {
                goto end_rounds;
            }
        }

    end_rounds:

        int comp_decision = decison(user_input, randomNumUpto3());

        if (comp_decision == 0)
        {
            score += 1;
            robo_score += 1;
        }
        else if (comp_decision == 1)
        {
            score += 1;
        }
        else if (comp_decision == -1)
        {
            robo_score += 1;
        }
    }

    printf("\n\nFinale Result:\nYour Score: %d\nRobot Score: %d\n", score, robo_score);

    if (score > robo_score)
    {
        printf("\nYou Won");
    }
    else if (score == robo_score)
    {
        printf("\nGame Draw");
    }
    else
    {
        printf("\nYou Lost");
    }
}

int decison(int user_input, int randomNum)
{
    if (user_input == randomNum)
    {
        return 0;
    }
    else if (user_input == 1)
    {
        if (user_input == 1 && randomNum == 2)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else if (user_input == 2)
    {
        if (user_input == 2 && randomNum == 2)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else if (user_input == 3)
    {
        if (user_input == 3 && randomNum == 1)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}