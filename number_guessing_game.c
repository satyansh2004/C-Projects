// Guessing a randome number under 10 chances
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate randome numbers
int random_num(int range)
{
    srand(time(NULL));
    int random = rand() % (range + 1);
    return random;
}

int main(void)
{
    int guess = 10, range = 100, user_guess = 1;
    int user_input;

    int score = 0;

    int randomValue = random_num(100);
    // printf("\nRandom num: %d", randomValue);

    while (user_guess != guess + 1)
    {
        printf("\nEnter your %d guess: ", user_guess);
        scanf("%d", &user_input);

        if (user_input == randomValue)
        {
            score = score + 1;
            goto end;
        }
        else if (user_input < randomValue)
        {
            printf("\nHint: Less than the VALUE");
        }
        else if (user_input > randomValue)
        {
            printf("\nHint: More than the VALUE");
        }

        user_guess = user_guess + 1;
    }
end:

    if (score == 1)
    {
        printf("\nYou Won!, right answer: %d", randomValue);
    }
    else
    {
        printf("\nYou Loose :-(, right answer: %d", randomValue);
    }
}